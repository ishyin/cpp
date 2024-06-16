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
    clusters.readdata();                          //获取数据
    clusters.genstartcore();                   //随机取簇中心
    for (generation = 0; generation < G; generation++) {
        //迭代
        condition = clusters.updatekmean(); //根据簇中心重新分簇
        clusters.gennewcore();                 //根据新簇获得新的簇中心
        clusters.count_acc();                  //计算成功分簇的百分比
        if (condition == OK) break;             //如果簇不再改变则跳出循环
    }
    clusters.show(condition, generation);
    clusters.text();
}