#pragma once
//#include<iostream>
#include<fstream>
#include<sstream>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<iomanip>
//#include<opencv2/opencv.hpp>
#include"Kmeans.h"


#define OK 1
#define ERROR 0

int key[K] = { 0 };

//using namespace std;
//using namespace cv;
int get_truthvalue(string s) {
    //����ӳ��
    string s1, s2, s3, s4;
    s1 = "setosa";
    s2 = "versicolor";
    s3 = "virginica";
    s4 = "Non-iris";
    if (s == s1) return 0;
    if (s == s2) return 1;
    if (s == s3) return 2;
    if (s == s4) return 3;

}
void Kmeans::readdata() {  //���ݻ�ȡ
    ifstream infile;
    float temp = 0;//��¼����ֵ
    string s;//��¼�β������
    int count = 0;
    dataset individual;
    /*
   ifstream�����ķ������ܣ�
   open():��һ���ļ�������һ���ļ������������ɹ��򿪷���true:
   is_open():��飬�ļ��ɹ��򿪷���true
   good():����ļ�����״̬(�ɶ�ȡ���д��)������ļ���״̬���ã�δ���������򷵻�true
   eof():����Ƿ��Ѿ������ļ�ĩβ�����򷵻�true
   close():�ر��ļ�
   */
    infile.open("iris.txt");
    if (!infile.is_open()) {
        cout << "Open file failure" << endl;
    }

    while (infile.good() && !infile.eof()) {
        count++;
        //���ݼ��е�5n��n=1,2,������������Ϊ�β�������࣬����ÿ��(count % (SIZE + 1) == 0)��ȡһ�������ground��ֵ
        if (count % (SIZE + 1) == 0) {
            infile >> s;//���ļ������������ζ�ȡ���ݣ��������ݴ洢������s��
            individual.ground = get_truthvalue(s);
            Data.push_back(individual);//ÿ�ֽ����������δ洢����individual�������ݼ�������
        }
        else {
            //ÿ�ֶ�ȡǰ�ĸ����೤����������곤����������feature[SIZE]����
            infile >> temp;
            individual.flower[count % (SIZE + 1) - 1] = temp;
        }
    }
    //size_t:��һ���������ͣ�ͨ�������ڱ�ʾ����Ĵ�С������������һ���޷����������ͣ�������������������Ĵ�С
    //�޷����������ͣ�ֻ�ܱ�ʾ�Ǹ�������û�з���λ
    size_t length = Data.size();
    cout << length << endl;
    infile.close();
}

//void Kmeans::genstartcore() {  //������ɳ�ʼ������
//    srand((int)time(NULL));
//    int length = Data.size();
//    int x, y, z;
//    int d;
//    int i = 0;
//
//    x = rand() % 50;
//    y = rand() % 50 + 50;
//    z = rand() % 50 + 100;
//    d = rand() % 50 + 150;
//
//    for (i = 0; i < SIZE; i++) {
//
//        core[0][i] = Data[x].flower[i];
//    }
//    for (i = 0; i < SIZE; i++) {
//
//        core[1][i] = Data[y].flower[i];
//    }
//    for (i = 0; i < SIZE; i++) {
//
//        core[2][i] = Data[z].flower[i];
//    }
//    for (i = 0; i < SIZE; i++) {
//
//        core[3][i] = Data[d].flower[i];
//    }
//
//}

void Kmeans::genstartcore() {  //������ɳ�ʼ�����ġ�
    srand((int)time(NULL));
    size_t length = Data.size();/*size_t �� C++ �е�һ���������ͣ�ͨ��������ʾ����Ĵ�С��������ĳ��ȡ�
    �����޷����������ͣ����С�ڲ�ͬ��ϵͳ�Ͽ��ܻ�������ͬ����ͨ���㹻���������κο��ܵĶ����С��*/
    int x, y, z,p;
    int i = 0;
    x = rand() % length;
    y = rand() % length;
    z = rand() % length;
    p = rand() % length;


    cout << "length=" << length << endl;
    for (i = 0; i < SIZE; i++) {
    	core[0][i] = Data[x].flower[i];
    }
    for (i = 0; i < SIZE; i++) {
    	core[1][i] = Data[y].flower[i];
    }
    for (i = 0; i < SIZE; i++) {
    	core[2][i] = Data[z].flower[i];
    	}
    for (i = 0; i < SIZE; i++) {
    core[3][i] = Data[p].flower[i];
        }
    }

void Kmeans::gennewcore() {  //���ݴ��������·ִ�

    int length = Data.size();
    int count1 = 0, count2 = 0, count3 = 0, count4 = 0;
    int i, j, k;
    float cores[K][SIZE] = { 0 };
    //�������л�����ͬһ����Ļ����ĸ������ۼ�����ƽ�������͵õ����µĴ�����
    for (k = 0; k != length; k++) {
        if (Data[k].pred == 0) {
            count1++;
            for (i = 0; i < SIZE; i++) {
                cores[0][i] += Data[k].flower[i];
            }
        }
        if (Data[k].pred == 1) {
            count2++;
            for (i = 0; i < SIZE; i++) {
                cores[1][i] += Data[k].flower[i];
            }
        }
        if (Data[k].pred == 2) {
            count3++;
            for (i = 0; i < SIZE; i++) {
                cores[2][i] += Data[k].flower[i];
            }
        }
        if (Data[k].pred == 3) {
            count4++;
            for (i = 0; i < SIZE; i++) {
                cores[3][i] += Data[k].flower[i];
            }
        }
    }
    for (i = 0; i < SIZE; i++) {

        cores[0][i] /= count1;
    }
    for (i = 0; i < SIZE; i++) {

        cores[1][i] /= count2;
    }
    for (i = 0; i < SIZE; i++) {

        cores[2][i] /= count3;
    }
    for (i = 0; i < SIZE; i++) {

        cores[3][i] /= count4;
    }
    for (i = 0; i < K; i++) {

        for (j = 0; j < SIZE; j++) {
            //abs:�������ֵ
            gap = abs(cores[i][j] - core[i][j]);//�������
            core[i][j] = cores[i][j];//����ѡȡ����
        }
    }

    /*if(difference<ZERO) return SUCCESS;       //��������ֹ����
    else return CONTINUE;*/
}

int Kmeans::updatekmean() {  // ���´ػ���µĴ�����

    int i, j, k;
    int count = 0; //�ɹ����䵽��ȷ�ص����ݵ�����
    int length = Data.size();
    for (k = 0; k != length; k++) {
        //����ÿ�������������ĵľ��루ŷ�Ͼ��룩
        for (i = 0; i != K; i++) {
            Data[k].distance[i] = 0;
            for (j = 0; j < SIZE; j++) {
                //ŷʽ����
                Data[k].distance[i] += sqrt(
                    (core[i][j] - Data[k].flower[j])
                    * (core[i][j] - Data[k].flower[j]));
                //�����پ���
            /*  Data[k].distance[i] += abs(center[i][j]-Data[k].feature[j]);*/
            }
        }
        //Ѱ����С����
        float shortest = (Data[k].distance[0] < Data[k].distance[1])
            ? Data[k].distance[0] : Data[k].distance[1];
        shortest = (shortest < Data[k].distance[2])
            ? shortest : Data[k].distance[2];
        shortest = (shortest < Data[k].distance[3] ? shortest : Data[k].distance[3]);
        for (i = 0; i < K; i++) {
            if (Data[k].distance[i] == shortest) {
                if (Data[k].pred == i) count++;
                else Data[k].pred = i;
            }
        }
    }
    if (length == count) return OK;
    else return ERROR;

}

void Kmeans::count_acc() {
    int i, j, success = 0;
    int length = Data.size();

    int flower[K][K] = { 0 };

    for (i = 0; i != length; i++)
    {
        if (Data[i].ground == 0) {   //��ʵΪ0  ����Ӧ�������֣�����Ϊ�����
            if (Data[i].pred == 0) flower[0][0]++;
            if (Data[i].pred == 1) flower[0][1]++;
            if (Data[i].pred == 2) flower[0][2]++;
            if (Data[i].pred == 3) flower[0][3]++;
        }
        else if (Data[i].ground == 1) {
            if (Data[i].pred == 0) flower[1][0]++;
            if (Data[i].pred == 1) flower[1][1]++;
            if (Data[i].pred == 2) flower[1][2]++;
            if (Data[i].pred == 3) flower[1][3]++;
        }
        else if (Data[i].ground == 2) {
            if (Data[i].pred == 0) flower[2][0]++;
            if (Data[i].pred == 1) flower[2][1]++;
            if (Data[i].pred == 2) flower[2][2]++;
            if (Data[i].pred == 3) flower[2][3]++;
        }
        else if (Data[i].ground == 3) {
            if (Data[i].pred == 0) flower[3][0]++;
            if (Data[i].pred == 1) flower[3][1]++;
            if (Data[i].pred == 2) flower[3][2]++;
            if (Data[i].pred == 3) flower[3][3]++;
        }

    }
    for (i = 0; i != K; i++) {
        if (flower[i][0] > flower[i][1] && flower[i][0] > flower[i][2] && flower[i][0] > flower[i][3])
            key[i] = 0;
        else if (flower[i][1] > flower[i][0] && flower[i][1] > flower[i][2] && flower[i][1] > flower[i][3])
            key[i] = 1;
        else if (flower[i][2] > flower[i][0] && flower[i][2] > flower[i][1] && flower[i][2] > flower[i][3])
            key[i] = 2;
        else if (flower[i][3] > flower[i][0] && flower[i][3] > flower[i][1] && flower[i][3] > flower[i][2])
            key[i] = 3;

    }
    //���ͨ��flower[][]��key[]ȷ��׼ȷ�ʣ�
    //--flower[][]��������ʾ����ǰ������ֵ��0��1��2����������ʾ������ֵ��0��1��2����
    //--key[]�������������������ֵ,key[i]��ֵ�������ǰ��ֵ
    //--����ǰΪ��һ�໨ʱ���жϾۺ������ֵi����flower[0][i]��λ�ý���+1������Ȼ��Ƚϵ�һ�и��е���ֵ��i����ֵ��͸�key[i]����һ�໨��Ӧ������ֵ������һ����ֵ�����ʾ��ǰ�ۺ�����ֵ��ȵ�����϶�
    //--����ǰΪ�ڶ��໨ʱ���жϾۺ������ֵi����flower[1][i]��λ�ý���+1������Ȼ��Ƚϵڶ��и��е���ֵ��i����ֵ��͸�key[i]���ڶ��໨��Ӧ������ֵ�����ڶ�����ֵ�����ʾ��ǰ�ۺ�����ֵ��ȵ�����϶�
    //--����ǰΪ�����໨ʱ���жϾۺ������ֵi����flower[2][i]��λ�ý���+1������Ȼ��Ƚϵ����и��е���ֵ��i����ֵ��͸�key[i]�������໨��Ӧ������ֵ������������ֵ�����ʾ��ǰ�ۺ�����ֵ��ȵ�����϶�
    for (j = 0; j != length; j++) {

        if (Data[j].pred == key[Data[j].ground]) success++;
    }
    accuracy = (float)success / length;

}

void Kmeans::show(int condition, int generation) {

    int length = Data.size();
    int i, j;

    for (i = 0; i != length; i++) {

        for (j = 0; j != SIZE; j++) {

            cout << "\t" << Data[i].flower[j];
        }
        cout << "\t" << Data[i].ground << "\t" << Data[i].pred << endl;
    }

    if (condition == OK) {
        cout << "����Ԥ��!" << endl;
        cout << "������ " << generation + 1 << " ��" << endl;
        cout << "��ȷ�� " << accuracy * 100 << "%";

    }
    if (condition == ERROR) {

        cout << "Ԥ��ʧ��" << endl;
        cout << "��ȷ�� " << accuracy * 100 << "%";
    }
}
//�������
void Kmeans::addData()
{
    srand(static_cast<unsigned int>(time(nullptr))); // ʹ�õ�ǰʱ����Ϊ����

    //��iris.txt��׷������
    ofstream irisFile("iris.txt", ios_base::app);
    if (!irisFile.is_open())
    {
        cerr << "Open file failture" << endl;

    }
    //���50���������
    const int num_rows = 50;
    const char* non_iris = "Non_Iris";
    for (int i = 0; i < num_rows; i++)
    {
        //�����ĸ����������
        float floats[4];
        for (int j = 0; j < 4; j++)
        {
            floats[j] = static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * 100.0f;
        }
        //��ʽ����д�����ݼ���
        irisFile << fixed << setprecision(2) << floats[0] << ' '
            << floats[1] << ' '
            << floats[2] << ' '
            << floats[3] << ' '
            << non_iris << endl;

    }
    irisFile.close();
}
void Kmeans::text()
{
    int numT = 0;
    int num = 0;
    char choice = 'y';
    while (choice == 'y')
    {
        num++;
        float num1, num2, num3, num4;
        int a1, a2;
        cout << "������һ�����ݣ�" << endl;
        cin >> num1 >> num2 >> num3 >> num4 >> a1;
        int i, k, j;
        //�������
        float dis[4] = { 0 };

        for (int i = 0; i < 4; i++)
        {
            dis[i] = sqrt((core[i][0] - num1) * (core[i][0] - num1)) + sqrt((core[i][1] - num2) * (core[i][1] - num2)) + sqrt((core[i][2] - num3) * (core[i][2] - num3)) + sqrt((core[i][3] - num4) * (core[i][3] - num4));
        }
        int min = 0;
        for (int i = 1; i < K; i++) {
            if (dis[i] < dis[min]) {
                min = i;
            }
        }
        for (int i = 0; i < K; i++)
        {
            if (key[i] == min)
            {
                min = i;
                break;
            }
        }

        //����С����
        if (min == 0)
        {
            cout << "Ԥ��ֵ��" << 0 << endl;
            Mat img = imread("iris1.png");
            namedWindow("��һ��");
            imshow("��һ��", img);
            waitKey(0);
        }
        if (min == 1)
        {
            cout << "Ԥ��ֵ��" << 1 << endl;
            Mat img = imread("iris2.png");
            namedWindow("�ڶ���");
            imshow("�ڶ���", img);
            waitKey(0);
        }

        if (min == 2)
        {

            cout << "Ԥ��ֵ��" << 2 << endl;
            Mat img = imread("iris3.png");
            namedWindow("������");
            imshow("������", img);
            waitKey(0);
        }

        if (min == 3)
        {

            cout << "Ԥ��ֵ��" << 3 << endl;
            Mat img = imread("iris4.png");
            namedWindow("�ǻ���");
            imshow("�ǻ���", img);
            waitKey(0);
        }
        if (min == a1)
            numT++;
        num++;
        //������numTת��Ϊfloat�ͣ��ڽ�������ʱ��������С�����ֵ���result�����Ϊ0��
        accuracy = ((float)(numT) / num) * 100;
        cout << fixed << setprecision(2) << accuracy << "%" << endl;
        accuracy = 0;
        cout << "continue?y/n:";
        cin >> choice;
    }
}
