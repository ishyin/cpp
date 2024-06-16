#pragma once
#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;
#define K 4
#define SIZE 4
class dataset {
public:
    float flower[SIZE];         //存储鸢尾花的四个特征
    int ground;                 //鸢尾花的真正种类
    int pred;                    //聚类后的种类
    float distance[K];           //每个样本到各簇中心的距离
    void show() {
        //显示输入数据
        cout << flower[0] << "\t" << flower[1] << "\t" << flower[2] << "\t"
            << flower[3] << "\t" << ground << endl;
    }
};
