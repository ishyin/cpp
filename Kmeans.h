#pragma once
#include<vector>
#include"dataset.h"

class Kmeans {

private:
    vector<dataset> Data;          //鸢尾花数据集
    float core[K][SIZE];       //三个簇中心位置
    float gap;            //和上一个簇中心的距离
    float accuracy;                //正确率

public:
    void addData();//添加数据
    void text();//测试代码
    void readdata();//数据获取
    void genstartcore();//生成初始质心集
    void gennewcore();//获得新的质心
    int updatekmean();// 计算每个点距离各簇中心的距离
    void count_acc();//计算准确率
    int select(const vector<dataset>& data, const float center[][SIZE], int k);
    void show(int condition, int generation);
};
