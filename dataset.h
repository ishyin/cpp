#pragma once
#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;
#define K 4
#define SIZE 4
class dataset {
public:
    float flower[SIZE];         //�洢�β�����ĸ�����
    int ground;                 //�β������������
    int pred;                    //����������
    float distance[K];           //ÿ���������������ĵľ���
    void show() {
        //��ʾ��������
        cout << flower[0] << "\t" << flower[1] << "\t" << flower[2] << "\t"
            << flower[3] << "\t" << ground << endl;
    }
};
