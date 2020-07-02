#include<iostream>
#include<string>
#include<math.h>
#include<time.h>
#include<iomanip>
#include<fstream>
#include<Windows.h>
using std::cout;
using std::cin;
using std::wcin;
using std::wcout;
using std::endl;
using std::string;
using std::setw;
using std::ifstream;
using std::ofstream;
class StudentMsg_0132lf {
protected:
	string name_0132lf;
	string sex_0132lf;
	string num_0132lf;
	double score1_0132lf, score2_0132lf, score3_0132lf;
	double SumScore_0132lf;
};//学生参数继承用
class Student_0132lf:protected StudentMsg_0132lf {
public:
	//Student_0132lf* head_0132lf;
	Student_0132lf* next_0132lf;
	Student_0132lf();
	~Student_0132lf();
	void GetDate_0132lf();//插入信息函数重载
	void GetDate_0132lf(string num_0132lf, string name_0132lf, string sex_0132lf,
		double score1_0132lf, double score2_0132lf, double score3_0132lf, 
		double SumScore_0132lf);
	void GetSomeDate_0132lf();
	void SetFakeDate_0132lf();//随机生成虚拟信息，骚气的功能
	void SetSomeFakeDate_0132lf();
	void FindDate_0132lf();//查找信息
	void FindDateByName_0132lf();
	void FindDateByNum_0132lf();
	void PrintDate_0132lf(Student_0132lf* p_0132lf);//输出节点信息
	void PrintDate_0132lf();
	void PrintAllDate_0132lf();
	void SortDate_0132lf();//排序
	void DelDate_0132lf();//删除信息
	void DelAllDate_0132lf();//清除所有信息
	void DelFileDate_0132lf();//清除硬盘信息
	void LoadDate_0132lf();//读取磁盘信息
	void SaveDate_0132lf();//保存数据到磁盘
	void ChangeDate_0132lf();//更改数据
	void Menu_0132lf();
};

//构造函数初始化列表
Student_0132lf::Student_0132lf() {
	next_0132lf = NULL;
}


Student_0132lf::~Student_0132lf() {

}
void Student_0132lf::GetDate_0132lf(string num_0132lf, string name_0132lf, string sex_0132lf,
	double score1_0132lf, double score2_0132lf, double score3_0132lf, double SumScore_0132lf) {
	Student_0132lf* temp_0132lf = this;
	while (temp_0132lf->next_0132lf) {
		temp_0132lf = temp_0132lf->next_0132lf;
	}
	temp_0132lf->next_0132lf = new Student_0132lf;
	temp_0132lf = temp_0132lf->next_0132lf;
	temp_0132lf->num_0132lf = num_0132lf;
	temp_0132lf->name_0132lf = name_0132lf;
	temp_0132lf->sex_0132lf = sex_0132lf;
	temp_0132lf->score1_0132lf = score1_0132lf;
	temp_0132lf->score2_0132lf = score2_0132lf;
	temp_0132lf->score3_0132lf = score3_0132lf;
	temp_0132lf->SumScore_0132lf = SumScore_0132lf;
}

void Student_0132lf::GetDate_0132lf() {
	Student_0132lf* temp_0132lf = this;
	while (temp_0132lf->next_0132lf) {
		temp_0132lf = temp_0132lf->next_0132lf;
	}
	cout <<"请输入学生信息 ：" << endl;
	temp_0132lf->next_0132lf = new Student_0132lf;
	temp_0132lf = temp_0132lf->next_0132lf;
	cout <<endl<< "姓名:";
	cin >> temp_0132lf->name_0132lf;
	cout << endl << "性别：";
	while (cin >> temp_0132lf->sex_0132lf, temp_0132lf->sex_0132lf != "男" && temp_0132lf->sex_0132lf != "女") {
		cout << endl << "您只能输入男|女" << endl << "性别:";
	}
	cout << endl << "学号：";
	while (cin >> temp_0132lf->num_0132lf, temp_0132lf->num_0132lf.length() != 12) {
		cout << endl << "请输入正确的学号（12位）" << endl << "学号：";
	}
	cout << endl << "A课、B课、C课成绩(空格隔开)：";
	while (cin >> temp_0132lf->score1_0132lf >> temp_0132lf->score2_0132lf >> temp_0132lf->score3_0132lf, 1) {
		if (temp_0132lf->score1_0132lf < 0 || temp_0132lf->score1_0132lf > 100) {
			cout << "请正确输入三科成绩[0,100]" << endl;
		}
		else if (temp_0132lf->score2_0132lf < 0 || temp_0132lf->score2_0132lf > 100) {
			cout << "请正确输入三科成绩[0,100]" << endl;
		}
		else if (temp_0132lf->score3_0132lf < 0 || temp_0132lf->score3_0132lf > 100) {
			cout << "请正确输入三科成绩[0,100]" << endl;
		}
		else
			break;
	}
	temp_0132lf->SumScore_0132lf = temp_0132lf->score1_0132lf + temp_0132lf->score2_0132lf + temp_0132lf->score3_0132lf;
}
void Student_0132lf::GetSomeDate_0132lf() {
	int n_0132lf;
	cout << "请输入您将录入的人数：";
	cin >> n_0132lf;
	while (n_0132lf--) {
		this->GetDate_0132lf();
	}
}
void Student_0132lf::PrintDate_0132lf(Student_0132lf* p_0132lf) {
	cout << "学号：" << p_0132lf->num_0132lf << "  " <<
		"姓名：" << setw(6) << p_0132lf->name_0132lf << " " <<
		"性别：" << "  " << p_0132lf->sex_0132lf << "  " <<
		"A、B、C三课成绩：" << setw(4) << p_0132lf->score1_0132lf << setw(4) <<
		p_0132lf->score2_0132lf << setw(4) <<
		p_0132lf->score3_0132lf << " " <<
		"总成绩：" << p_0132lf->SumScore_0132lf << endl;
}
void Student_0132lf::PrintDate_0132lf() {
	cout << "姓名：" << setw(6) << name_0132lf << " " <<
		"性别：" << "  " << sex_0132lf << "  " <<
		"学号：" << num_0132lf << "  " <<
		"A、B、C三课成绩：" << setw(5) << score1_0132lf << setw(5) <<
		score2_0132lf << setw(5) <<
		score3_0132lf << " " <<
		"总成绩：" << SumScore_0132lf << endl;
}

void Student_0132lf::PrintAllDate_0132lf() {
	Student_0132lf* temp_0132lf = this->next_0132lf;
	while (temp_0132lf) {
		temp_0132lf->PrintDate_0132lf();
		temp_0132lf = temp_0132lf->next_0132lf;
	}
}
void Student_0132lf::FindDate_0132lf() {
	int flag_0132lf;
	cout << endl << "					请按键选择查找方式(1: 姓 名 2：学 号 ):";
	cin >> flag_0132lf;
	switch (flag_0132lf) {
	case 1:
		this->FindDateByName_0132lf();
		break;
	case 2:
		this->FindDateByNum_0132lf();
		break;
	default:
		cout << "您只能输入1或2" << endl;
		break;
	}
	return;
}

void Student_0132lf::FindDateByName_0132lf() {
	cout << "请输入您想查找的名字：";
	string tname_0132lf;
	cin >> tname_0132lf;
	int flag_0132lf = 0;
	
	Student_0132lf* temp_0132lf = this;
	
	for (; temp_0132lf; temp_0132lf = temp_0132lf->next_0132lf) {
		if (temp_0132lf->name_0132lf == tname_0132lf)
			temp_0132lf->PrintDate_0132lf(), flag_0132lf = 1;
	}
	if (!flag_0132lf)
		cout << endl<< "没有找到您所输入的名字，请检查是否输入错误" << endl;
}

void Student_0132lf::FindDateByNum_0132lf() {
	cout << "请输入您想查找的学号：";
	string tnum_0132lf;
	cin >> tnum_0132lf;
	int flag_0132lf = 0;

	Student_0132lf* temp_0132lf = this;

	for (; temp_0132lf; temp_0132lf = temp_0132lf->next_0132lf) {
		if (temp_0132lf->num_0132lf == tnum_0132lf)
			temp_0132lf->PrintDate_0132lf(), flag_0132lf = 1;
	}
	if (!flag_0132lf)
		cout << endl << "没有找到您所输入的学号，请检查是否输入错误" << endl;
}

void Student_0132lf::LoadDate_0132lf() {
	ifstream in_0132lf;
	in_0132lf.open("student.txt");
	if (in_0132lf.fail()) {
		ofstream("student.txt");
		in_0132lf.open("student.txt");
	}
	//printf("%p ", in_0132lf);
	Student_0132lf* temp_0132lf = this;
	//printf("%p ", this);
	string c_0132lf;
	in_0132lf >> c_0132lf;
	if (in_0132lf.eof()) {
		cout << "您还未保存有任何学生信息" << endl;
		return;
	}
	in_0132lf.seekg(0);
	while (!in_0132lf.eof()) {
		string tnum_0132lf;
		string tname_0132lf;
		string tsex_0132lf;
		double tscore1_0132lf;
		double tscore2_0132lf;
		double tscore3_0132lf;
		double tSumScore_0132lf;
		in_0132lf >> tnum_0132lf >> tname_0132lf >> tsex_0132lf >>
			tscore1_0132lf >> tscore2_0132lf >> tscore3_0132lf >> tSumScore_0132lf;
		//cout << tnum_0132lf << tname_0132lf << tsex_0132lf <<
			//tscore1_0132lf << tscore2_0132lf << tscore3_0132lf << tSumScore_0132lf;
		this->GetDate_0132lf(tnum_0132lf,tname_0132lf,tsex_0132lf,
			tscore1_0132lf,tscore2_0132lf,tscore3_0132lf,tSumScore_0132lf);
		in_0132lf.get();
		if (in_0132lf.peek() == EOF)
			break;
	}
	in_0132lf.close();
	cout << "信息载入完成" << endl;
}

void Student_0132lf::SaveDate_0132lf() {
	ofstream file_0132lf;
	file_0132lf.open("student.txt");
	if (!file_0132lf) {
		cout << "save error" << endl;
		return;
	}
	Student_0132lf* temp_0132lf = this;
	temp_0132lf = temp_0132lf->next_0132lf;
	while (temp_0132lf) {
		file_0132lf<< temp_0132lf->num_0132lf << "  " <<
			"  " << setw(8) << temp_0132lf->name_0132lf << " " <<
			"  " << "  " << temp_0132lf->sex_0132lf << "  " <<
			"  " << setw(6) << temp_0132lf->score1_0132lf<<"  "
			<< setw(6) <<temp_0132lf->score2_0132lf << setw(6) <<
			temp_0132lf->score3_0132lf << " " <<
			"  " << temp_0132lf->SumScore_0132lf << endl;
		temp_0132lf = temp_0132lf->next_0132lf;
	}
	cout << "保存成功！" << endl;
}

void Student_0132lf::DelFileDate_0132lf() {
	ofstream("student.txt");
}

void Student_0132lf::DelAllDate_0132lf() {
	DelFileDate_0132lf();
	Student_0132lf* temp_0132lf = this->next_0132lf;
	while (temp_0132lf) {
		Student_0132lf* p_0132lf = temp_0132lf;
		temp_0132lf = temp_0132lf->next_0132lf;
		delete p_0132lf;
		p_0132lf = NULL;
	}
	this->DelFileDate_0132lf();
	this->next_0132lf = NULL;
	cout << "清除成功" << endl;
}
void Student_0132lf::DelDate_0132lf() {
	cout << "请输入您想删除的学号：";
	string tnum_0132lf;
	cin >> tnum_0132lf;
	int flag_0132lf = 0;

	Student_0132lf* temp_0132lf = this;

	for (; temp_0132lf->next_0132lf; temp_0132lf = temp_0132lf->next_0132lf) {
		if (temp_0132lf->next_0132lf->num_0132lf == tnum_0132lf) {
			Student_0132lf* p_0132lf = temp_0132lf->next_0132lf;
			temp_0132lf->next_0132lf = temp_0132lf->next_0132lf->next_0132lf;
			cout << "删除：" << endl;
			p_0132lf->PrintDate_0132lf();
			delete p_0132lf;
			p_0132lf = NULL;
			flag_0132lf = 1;
		}
	}
	if (!flag_0132lf)
		cout << endl << "没有找到您所输入的学号，请检查是否输入错误" << endl;
}
void Student_0132lf::ChangeDate_0132lf() {
	cout << "请输入您想更改人的学号：";
	string tnum_0132lf;
	cin >> tnum_0132lf;
	int flag_0132lf = 0;

	Student_0132lf* temp_0132lf = this;
	//可优化
	for (; temp_0132lf; temp_0132lf = temp_0132lf->next_0132lf) {
		if (temp_0132lf->num_0132lf == tnum_0132lf) {
			cout << "您想修改的数据是：" << endl;
			temp_0132lf->PrintDate_0132lf();
			cout << "请输入学生信息 ：" << endl;
			cout << endl << "姓名:";
			cin >> temp_0132lf->name_0132lf;
			cout << endl << "性别：";
			while (cin >> temp_0132lf->sex_0132lf, temp_0132lf->sex_0132lf != "男" && temp_0132lf->sex_0132lf != "女") {
				cout << endl << "您只能输入男|女" << endl << "性别:";
			}
			cout << endl << "学号：";
			while (cin >> temp_0132lf->num_0132lf, temp_0132lf->num_0132lf.length() != 12) {
				cout << endl << "请输入正确的学号（12位）" << endl << "学号：";
			}
			cout << endl << "A课、B课、C课成绩(空格隔开)：";
			while (cin >> temp_0132lf->score1_0132lf >> temp_0132lf->score2_0132lf >> temp_0132lf->score3_0132lf, 1) {
				if (temp_0132lf->score1_0132lf < 0 || temp_0132lf->score1_0132lf > 100) {
					cout << "请正确输入三科成绩[0,100]" << endl;
				}
				else if (temp_0132lf->score2_0132lf < 0 || temp_0132lf->score2_0132lf > 100) {
					cout << "请正确输入三科成绩[0,100]" << endl;
				}
				else if (temp_0132lf->score3_0132lf < 0 || temp_0132lf->score3_0132lf > 100) {
					cout << "请正确输入三科成绩[0,100]" << endl;
				}
				else
					break;
			}
			temp_0132lf->SumScore_0132lf = temp_0132lf->score1_0132lf + temp_0132lf->score2_0132lf + temp_0132lf->score3_0132lf;
			flag_0132lf = 1;
			break;
		}
	}
	if (!flag_0132lf)
		cout << endl << "没有找到您所输入的学号，请检查是否输入错误" << endl;
}

void Student_0132lf::SortDate_0132lf() {
	cout << "真是遗憾呢！您只能选择学号排序方式(ps:我不想再敲了！！！)："<<endl;
	if (!this->next_0132lf || !this->next_0132lf->next_0132lf) {
		cout << "区区一两个数才没有资格排序呢！" << endl;
		return;
	}
	Student_0132lf* slow_0132lf = this->next_0132lf;
	Student_0132lf* temp_0132lf = slow_0132lf->next_0132lf;//就不让你叫fast，气不气？
	for (; slow_0132lf->next_0132lf; slow_0132lf = slow_0132lf->next_0132lf) {//可优化，不想动脑子了
		for (temp_0132lf = slow_0132lf->next_0132lf;temp_0132lf ; temp_0132lf = temp_0132lf->next_0132lf) {
			if (slow_0132lf->SumScore_0132lf < temp_0132lf->SumScore_0132lf) {
				string tnum_0132lf = temp_0132lf->num_0132lf;
				string tname_0132lf = temp_0132lf->name_0132lf;
				string tsex_0132lf = temp_0132lf->sex_0132lf;
				double tscore1_0132lf = temp_0132lf->score1_0132lf;
				double tscore2_0132lf = temp_0132lf->score2_0132lf;
				double tscore3_0132lf = temp_0132lf->score3_0132lf;
				double tSumScore_0132lf = temp_0132lf->SumScore_0132lf;
				temp_0132lf->num_0132lf = slow_0132lf->num_0132lf, temp_0132lf->name_0132lf = slow_0132lf->name_0132lf;
				temp_0132lf->sex_0132lf = slow_0132lf->sex_0132lf, temp_0132lf->score1_0132lf = slow_0132lf->score1_0132lf;
				temp_0132lf->score2_0132lf = slow_0132lf->score2_0132lf, temp_0132lf->score3_0132lf = slow_0132lf->score3_0132lf;
				temp_0132lf->SumScore_0132lf = slow_0132lf->SumScore_0132lf;
				slow_0132lf->num_0132lf = tnum_0132lf, slow_0132lf->name_0132lf = tname_0132lf;
				slow_0132lf->sex_0132lf = tsex_0132lf, slow_0132lf->score1_0132lf = tscore1_0132lf;
				slow_0132lf->score2_0132lf = tscore2_0132lf, slow_0132lf->score3_0132lf = tscore3_0132lf;
				slow_0132lf->SumScore_0132lf = tSumScore_0132lf;
			}
		}
	}
	cout << "排序完成！" << endl;
}
void Student_0132lf::SetFakeDate_0132lf() {
	Sleep(400);
	srand(time(0));
	int flag_0132lf;
	string a_0132lf("王赵李章黄张熊");
	string b_0132lf("铁如凡小四多大海富优秀");
	string c_0132lf = "花开凡贵柱鱼笨壮优秀";
	string tnum_0132lf,tname_0132lf,tsex_0132lf;
	double tscore1_0132lf ,tscore2_0132lf, tscore3_0132lf,tSumScore_0132lf;
	flag_0132lf = rand() % 7*2;
	tname_0132lf += a_0132lf[flag_0132lf];
	tname_0132lf += a_0132lf[flag_0132lf+1];
	if (rand() % 2) {
		flag_0132lf = rand() % 11 * 2;
		tname_0132lf += b_0132lf[flag_0132lf];
		tname_0132lf += b_0132lf[flag_0132lf + 1];
	}
	Sleep(600);
	srand(time(NULL));
	flag_0132lf = rand() % 10 * 2;
	tname_0132lf += c_0132lf[flag_0132lf];
	tname_0132lf += c_0132lf[flag_0132lf + 1];
	if (rand() % 2)
		tsex_0132lf = "男";
	else {
		tsex_0132lf = "女";
	}
	cout << tname_0132lf << endl;
	tnum_0132lf = "20193407";
	tnum_0132lf += std::to_string(rand() % 8999 + 1000);
	tscore1_0132lf = double(rand() % 1000) / 10;
	tscore2_0132lf = double(rand() % 1000) / 10;
	tscore3_0132lf = double(rand() % 1000) / 10;
	tSumScore_0132lf = tscore1_0132lf + tscore2_0132lf + tscore3_0132lf;
	this->GetDate_0132lf(tnum_0132lf, tname_0132lf, tsex_0132lf,
		tscore1_0132lf, tscore2_0132lf, tscore3_0132lf, tSumScore_0132lf);
}
void Student_0132lf::SetSomeFakeDate_0132lf() {
	cout << "取名鬼才李某人在线取名：" << endl;
	cout << "请输入你想生成的虚拟信息个数：";
	int flag_0132lf;
	cin >> flag_0132lf;
	while (flag_0132lf--) {
		this->SetFakeDate_0132lf();
	}
}

void Student_0132lf::Menu_0132lf() {
	system("color 2");
	cout << "\t\t\t\t" << "******************************************************" << endl;
	cout << "\t\t\t\t" << "******	    学  生  信  息  系  统		******" << endl;
	cout << "\t\t\t\t" << "******		0.保存并退出系统		******" << endl;
	cout << "\t\t\t\t" << "******		1.从硬盘读取学生信息		******" << endl;
	cout << "\t\t\t\t" << "******		2.添加新的学生信息		******" << endl;
	cout << "\t\t\t\t" << "******		3.批量添加学生信息		******" << endl;
	cout << "\t\t\t\t" << "******		4.删除已有学生信息		******" << endl;
	cout << "\t\t\t\t" << "******		5.查找已有学生信息		******" << endl;
	cout << "\t\t\t\t" << "******		6.修改已有学生信息		******" << endl;
	cout << "\t\t\t\t" << "******		7.输出所有学生信息		******" << endl;
	cout << "\t\t\t\t" << "******		8.清除现有学生信息		******" << endl;
	cout << "\t\t\t\t" << "******		9.随机生成学生信息		******" << endl;
	cout << "\t\t\t\t" << "******		10.排序生成学生信息		******" << endl;
}

int main() {
	
	Student_0132lf* head_0132lf = new Student_0132lf;//头节点
	int flag_0132lf = 20;
	while (flag_0132lf--) {
		cout << ">>";
		Sleep(50);
	}
	head_0132lf->LoadDate_0132lf();
	cout << endl <<"加载完成" << endl;
	Sleep(1000);
	system("pause");
	while (1) {
		system("cls");
		head_0132lf->Menu_0132lf();
		cout << "\t\t\t请按键选择:";
		cin >> flag_0132lf;
		switch (flag_0132lf) {
			case 0:
				head_0132lf->SaveDate_0132lf();
				exit(0);
			case 1:
				head_0132lf->LoadDate_0132lf();
				break;
			case 2:
				head_0132lf->GetDate_0132lf();
				system("pause");
				break;
			case 3:head_0132lf->GetSomeDate_0132lf();
				system("pause");
				break;
			case 4:
				head_0132lf->DelDate_0132lf();
				system("pause");
				break;
			case 5:
				head_0132lf->FindDate_0132lf();
				system("pause");
				break;
			case 6:
				head_0132lf->ChangeDate_0132lf();
				system("pause");
				break;
			case 7:
				head_0132lf->PrintAllDate_0132lf();
				system("pause");
				break;
			case 8:
				head_0132lf->DelAllDate_0132lf();
				system("pause");
				break;
			case 9:
				head_0132lf->SetSomeFakeDate_0132lf();
				system("pause");
				break;
			case 10:
				head_0132lf->SortDate_0132lf();
				break;
			default:
				break;
		}
	}
	return 0;
}


