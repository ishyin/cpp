#pragma once
//#include<iostream>
#include "Kmeans.h"

//#include<opencv2/opencv.hpp>
#define G 50
#define OK 1
#define ERROR 0
//using namespace cv;
using namespace std;
int main() {
    Kmeans clusters;
    int generation = 0, condition = 0;
    //clusters.addData();
    clusters.readdata();                          //��ȡ����
    clusters.genstartcore();                   //���ȡ������
    for (generation = 0; generation < G; generation++) {
        //����
        condition = clusters.updatekmean(); //���ݴ��������·ִ�
        clusters.gennewcore();                 //�����´ػ���µĴ�����
        clusters.count_acc();                  //����ɹ��ִصİٷֱ�
        if (condition == OK) break;             //����ز��ٸı�������ѭ��
    }
    clusters.show(condition, generation);
    clusters.text();
}