#define _CRT_SECURE_NO_WARNINGS 1

//#include <iostream>
//#include <map>
//#include <string>
//#include <vector>
//#include <algorithm> // 需要包含algorithm头文件
//
//int main() {
//    std::string str;
//    std::getline(std::cin, str); // 使用getline读取包含空格的输入
//
//    std::vector<char> sign{ ' ', ',', '.' }; // 英文标点和空格作为分隔符
//    std::vector<std::string> words;
//    std::map<char, int> countMap;
//
//    int begin = 0;
//    for (int i = 0; i < str.size(); ++i) {
//        if (std::find(sign.begin(), sign.end(), str[i]) != sign.end()) {
//            if (i > begin) {
//                words.push_back(str.substr(begin, i - begin));
//            }
//            begin = i + 1;
//        }
//    }
//    if (begin < str.size()) {
//        words.push_back(str.substr(begin));
//    }
//
//    int countPD = 0;
//    for (const auto& word : words) {
//        if (word.size() >= 2 && word.substr(0, 2) == "PD") {
//            ++countPD;
//        }
//        for (char ch : word) {
//            countMap[ch]++;
//        }
//    }
//
//    std::cout << "单词个数：" << words.size()
//        << " PD开头单词个数: " << countPD << std::endl;
//    for (const auto& pair : countMap) {
//        std::cout << pair.first << " : " << pair.second << std::endl;
//    }
//
//    return 0;
//}
#include <iostream>
using namespace std;

//#pragma pack(4)

//class Base {
//public:
//	int a = 0;
//	/*virtual void print() {
//		cout << "Base\n";
//	}*/
//};
//class Derive : public Base {
//public:
//	/*void print() {
//		cout << "Base\n";
//	}*/
//	int a = 2;
//};
//
//int main() {
//	Base a;
//	Derive b;
//	cout << "sizeof a: " << sizeof(a) << endl;
//	cout << "sizeof b: " << sizeof(b) << endl;
//	std::cout << "Base alignment: " << alignof(Base) << '\n';
//	std::cout << "Derive alignment: " << alignof(Derive) << '\n';
//	return 0;
//}

//int main()
//{
//	const char* a = "BASIC";
//	for (int i = 4; i >= 0; i--)
//		cout.put(*(a + i));
//	cout.put('\n');
//		return 0;
//}

//int main()
//{
//	//char url[30] = { 0 };
//	////读取一行字符串
//	//cin.getline(url, 10);
//	////输出上一条语句读取字符串的个数
//	//int len = cin.gcount();
//	//cout << "读取了 " << len << " 个字符" << endl;
//	////输出 url 数组存储的字符串
//	//cout.write(url, len-1);
//	//cout << endl;
//	//cin >> url;
//	//cout << url;
//
//	/*char ch[20];
//	cout << "enter a sentence:" << endl;
//	cin.get(ch[0]);
//	cout << ch[0] << endl; return 0;
//	return 0;*/
//	int n;
//	cin.ignore(4, 'c');
//	cin >> n;
//	cout << n;
//	return 0;
//}

//int main()
//{
//	const char* filename = "log.txt";
//	FILE* fp = fopen(filename,"r+");
//	if (fp == NULL)
//	{
//		cout << "cann't open the file!\n";
//		return -1;
//	}
//	char buf[200];
//	size_t n = fread(buf, 1, 128, fp);
//	buf[n] = '\0';
//	cout << "the data in file is following:\n" << buf << endl;
//	for (int i = 0; i < n; i++)
//	{
//		if (buf[i] >= 'a' && buf[i] <= 'z')
//			buf[i] = buf[i] - 32;
//		else
//			if (buf[i] >= 'A' && buf[i] <= 'Z')
//				buf[i] = buf[i] + 32;
//	}
//	cout << "the changed data is :" << buf << endl;
//	rewind(fp); // 重置文件指针从头开始
//	fwrite(buf, 1, n, fp);
//	fclose(fp);
//
//	return 0;
//}
//#include <fstream>
//
//int main()
//{
//	char filename1[256], filename2[256];
//	char buf[300];
//	cout << "Input source file name: "; cin >> filename1;
//	cout << "Input destination: "; cin >> filename2;
//	fstream infile, outfile;
//	infile.open(filename1, ios::in);
//	if (!infile) {
//		cout << "打开失败" << endl;
//	}
//	outfile.open(filename2, ios::out);
//	while (infile.getline(buf, 300))
//		outfile << buf << endl;
//	infile.seekg(100, ios::beg);
//	infile.seekp(100, ios::cur);
//	infile.seekp(-100, ios::cur);
//	outfile.close();
//	infile.close();
//}

#include <fstream>
#include <iostream>
#include <string.h>
using namespace std;
struct student
{
    int num; char name[20]; float score;
};

//int main()
//{
//    int i;
//    student stud[5] = { 1001,"li",85,1002,"fun",97.5,1004,"wang",54,1006,"tan",76.5,1010,"ling",96 };
//    fstream iofile;
//    iofile.open("log.txt", ios::in | ios::out|ios::trunc);
//    if (!iofile)
//    {
//        cerr << "open error!" << endl;
//        exit(-1);
//    }
//    for (i = 0; i < 5; i++)iofile.write((char*)&stud[i], sizeof(stud[i]));
//
//    student stud1[5];
//    for (i = 0; i < 5; i = i + 2)
//    {
//        iofile.seekg(i * sizeof(stud[i]), ios::beg);
//        iofile.read((char*)&stud1[i / 2], sizeof(stud1[i]));
//        cout << stud1[i / 2].num << " " << stud1[i / 2].name << " " << stud1[i / 2].score << endl;
//    }
//    cout << endl;
//    stud[2].num = 1012;
//    strcpy(stud[2].name, "wu");
//    stud[2].score = 60;
//    iofile.seekp(2 * sizeof(stud[0]), ios::beg);
//    iofile.write((char*)&stud[2], sizeof(stud[2]));
//    iofile.seekg(0, ios::beg);
//    for (i = 0; i < 5; i++)
//    {
//        iofile.read((char*)&stud[i], sizeof(stud[i]));
//        cout << stud[i].num << " " << stud[i].name << " " << stud[i].score << endl;
//    }
//    iofile.close();
//
//    return 0;
//}


//int main() {
//    const char* msg = "I am a man";
//    const char* test = "You are";
//    fstream iofile;
//    cout <<"sizeof(msg): " << strlen(msg) << endl;
//
//    iofile.open("log.txt", ios::in|ios::out|ios::trunc);
//    iofile.write(msg, strlen(msg));
//    iofile.seekp(0);
//    iofile.write(test, strlen(test));
//
//    iofile.close();
//    return 0;
//}

#include <string>
int main()
{
    string str1;
    str1 = "ni hao";
    const char* arr = str1.c_str();
    cout << arr << endl;

    return 0;
}