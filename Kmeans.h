#pragma once
#include<vector>
#include"dataset.h"

class Kmeans {

private:
    vector<dataset> Data;          //�β�����ݼ�
    float core[K][SIZE];       //����������λ��
    float gap;            //����һ�������ĵľ���
    float accuracy;                //��ȷ��

public:
    void addData();//�������
    void text();//���Դ���
    void readdata();//���ݻ�ȡ
    void genstartcore();//���ɳ�ʼ���ļ�
    void gennewcore();//����µ�����
    int updatekmean();// ����ÿ�������������ĵľ���
    void count_acc();//����׼ȷ��
    int select(const vector<dataset>& data, const float center[][SIZE], int k);
    void show(int condition, int generation);
};
