#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include <mutex>
#include <atomic>

using namespace std;

static void Print(int n, const string& name) {
	for (size_t i = 0; i < n; i++) {
		cout << this_thread::get_id()<<": " << i << " : " << "Times" << ": "<<name<<endl;
	}
}
static void Print1(int n) {
	for (size_t i = 0; i < n; i++) {
		cout << this_thread::get_id() << ": " << i << " : " << "Times" << endl;
	}
}
//
//int main() {
//	// 支持多参数
//	thread t1(Print, 500, 1);
//	thread t2(Print, 500, 1000);
//	
//	cout << "线程1id" << t1.get_id() << endl;
//	cout << "线程2id" << t2.get_id() << endl;
//
//	t1.join();
//	t2.join();
//	return 0;
//}


//int main() {
//	size_t n;
//	cin >> n;
//
//	vector<thread> vTh(n);
//	int j = 0;
//	for (auto& thd : vTh) {
//		// 移动赋值
//		thd = thread(Print, 10, to_string(j++) + "线程");
//	}
//
//	for (auto& thd : vTh) {
//		thd.join();
//	}
//
//	return 0;
//}

static void Prints(int n, int j, const string& s, mutex& m) {
	for (size_t i = 0; i < j+n; i++) {
		m.lock();
		cout << this_thread::get_id() << ": " << i  << endl;
		m.unlock();
	}
}

//void testMutex() {
//	mutex mtx;
//	thread t1(Prints, 100, 1, "我是阿Q", mtx);
//	thread t2(Prints, 100, 1000, "我是达西", mtx);
//
//	t1.join();
//	t2.join();
//
//}
//int main() {
//	size_t n1 = 0;
//	size_t n2 = 0;
//	mutex mx;
//	cin >> n1 >> n2;
//	int x = 0;
//	thread th1([n1, &x, &mx]() {
//		for (size_t i = 0; i < n1; i++) {
//			mx.lock();
//			++x;
//			mx.unlock();
//		}
//		});
//	thread th2([n2, &x, &mx]() {
//		for (size_t i = 0; i < n2; i++) {
//			mx.lock();
//			++x;
//			mx.unlock();
//		}
//		});
//	th1.join();
//	th2.join();
//	cout << x;
//	return 0;
//}

// 测试ref函数
void TestRef() {
	int x = 0;
	auto a = ref(x);
	++a;
	cout << x << endl;
}

template<class Lock>
class LockGuard {
public:
	LockGuard(Lock& lk):_lk(lk){
		_lk.lock();
	}
	~LockGuard() {
		_lk.unlock();
	}
private:
	Lock& _lk;
};

// 交替打印
void PrintNumByano() {
	mutex mtx;
	int x = 1;
	condition_variable cv;
	bool flag = false;// 1. 保证t1 先运行；2. 交替运行

	thread t1([&]() {
		for (int i = 0; i < 100; i++) {
			unique_lock<mutex> lock(mtx);
			while (flag)
				cv.wait(lock);
			cout << this_thread::get_id() << " : " << x << endl;
			++x;
			flag = true;
			cv.notify_one(); // t1 nodify_one 的时候，t2还没有wait
		}
	});
	thread t2([&]() {
		for (int i = 0; i < 100; i++) {
			unique_lock<mutex> lock(mtx);
			while (!flag)
				cv.wait(lock);
			cout << this_thread::get_id() << " : " << x << endl;
			++x;
			flag = false;
			cv.notify_one();
		}
	});
	t1.join();
	t2.join();
}
void TestAutoMic() {
	atomic<int> i = 0; // 内部类似自旋
	++i;
	cout << i << endl;
}
int main() {
	//testMutex();
	//TestRef();
	//PrintNumByano();
	TestAutoMic();
	return 0;
}