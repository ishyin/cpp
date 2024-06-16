//#pragma once
////#include<iostream>
//#include<fstream>
//#include<sstream>
//#include<cmath>
//#include<ctime>
//#include<algorithm>
//#include<iomanip>
////#include<opencv2/opencv.hpp>
//#include"Kmeans.h"
//
//
//#define OK 1
//#define ERROR 0
//
//int key[K] = { 0 };
//
////using namespace std;
////using namespace cv;
//int get_truthvalue(string s) {
//    //数据映射
//    string s1, s2, s3, s4;
//    s1 = "setosa";
//    s2 = "versicolor";
//    s3 = "virginica";
//    s4 = "Non-iris";
//    if (s == s1) return 0;
//    if (s == s2) return 1;
//    if (s == s3) return 2;
//    if (s == s4) return 3;
//
//}
//void Kmeans::readdata() {  //数据获取
//    ifstream infile;
//    float temp = 0;//记录特征值
//    string s;//记录鸢尾花种类
//    int count = 0;
//    dataset individual;
//    /*
//   ifstream类对象的方法介绍：
//   open():打开一个文件，接受一个文件名做参数，成功打开返回true:
//   is_open():检查，文件成功打开返回true
//   good():检查文件流的状态(可读取与可写入)，如果文件流状态良好，未遇到错误则返回true
//   eof():检查是否已经到达文件末尾，是则返回true
//   close():关闭文件
//   */
//    infile.open("iris.txt");
//    if (!infile.is_open()) {
//        cout << "Open file failure" << endl;
//    }
//
//    while (infile.good() && !infile.eof()) {
//        count++;
//        //数据集中第5n（n=1,2,……）个数据为鸢尾花的种类，所以每轮(count % (SIZE + 1) == 0)读取一次种类给ground赋值
//        if (count % (SIZE + 1) == 0) {
//            infile >> s;//从文件输入流中依次读取数据，并将数据存储到变量s中
//            individual.ground = get_truthvalue(s);
//            Data.push_back(individual);//每轮结束进行依次存储，将individual存入数据集数组中
//        }
//        else {
//            //每轮读取前四个花萼长、花萼宽、花瓣长、花瓣宽存入feature[SIZE]数组
//            infile >> temp;
//            individual.flower[count % (SIZE + 1) - 1] = temp;
//        }
//    }
//    //size_t:是一种数据类型，通常被用于表示对象的大小或索引。它是一个无符号整数类型，可以容纳数组或容器的大小
//    //无符号整数类型：只能表示非负整数，没有符号位
//    size_t length = Data.size();
//    cout << length << endl;
//    infile.close();
//}
//
////void Kmeans::genstartcore() {  //随机生成初始簇中心
////    srand((int)time(NULL));
////    int length = Data.size();
////    int x, y, z;
////    int d;
////    int i = 0;
////
////    x = rand() % 50;
////    y = rand() % 50 + 50;
////    z = rand() % 50 + 100;
////    d = rand() % 50 + 150;
////
////    for (i = 0; i < SIZE; i++) {
////
////        core[0][i] = Data[x].flower[i];
////    }
////    for (i = 0; i < SIZE; i++) {
////
////        core[1][i] = Data[y].flower[i];
////    }
////    for (i = 0; i < SIZE; i++) {
////
////        core[2][i] = Data[z].flower[i];
////    }
////    for (i = 0; i < SIZE; i++) {
////
////        core[3][i] = Data[d].flower[i];
////    }
////
////}
//
//void Kmeans::gennewcore() {  //根据簇中心重新分簇
//
//    int length = Data.size();
//    int count1 = 0, count2 = 0, count3 = 0, count4 = 0;
//    int i, j, k;
//    float cores[K][SIZE] = { 0 };
//    //遍历所有花，将同一种类的花的四个数据累加再求平均数，就得到了新的簇中心
//    for (k = 0; k != length; k++) {
//        if (Data[k].pred == 0) {
//            count1++;
//            for (i = 0; i < SIZE; i++) {
//                cores[0][i] += Data[k].flower[i];
//            }
//        }
//        if (Data[k].pred == 1) {
//            count2++;
//            for (i = 0; i < SIZE; i++) {
//                cores[1][i] += Data[k].flower[i];
//            }
//        }
//        if (Data[k].pred == 2) {
//            count3++;
//            for (i = 0; i < SIZE; i++) {
//                cores[2][i] += Data[k].flower[i];
//            }
//        }
//        if (Data[k].pred == 3) {
//            count4++;
//            for (i = 0; i < SIZE; i++) {
//                cores[3][i] += Data[k].flower[i];
//            }
//        }
//    }
//    for (i = 0; i < SIZE; i++) {
//
//        cores[0][i] /= count1;
//    }
//    for (i = 0; i < SIZE; i++) {
//
//        cores[1][i] /= count2;
//    }
//    for (i = 0; i < SIZE; i++) {
//
//        cores[2][i] /= count3;
//    }
//    for (i = 0; i < SIZE; i++) {
//
//        cores[3][i] /= count4;
//    }
//    for (i = 0; i < K; i++) {
//
//        for (j = 0; j < SIZE; j++) {
//            //abs:计算绝对值
//            gap = abs(cores[i][j] - core[i][j]);//计算距离
//            core[i][j] = cores[i][j];//重新选取中心
//        }
//    }
//
//    /*if(difference<ZERO) return SUCCESS;       //曾经的终止条件
//    else return CONTINUE;*/
//}
//
//int Kmeans::updatekmean() {  // 更新簇获得新的簇中心
//
//    int i, j, k;
//    int count = 0; //成功分配到正确簇的数据点数量
//    int length = Data.size();
//    for (k = 0; k != length; k++) {
//        //计算每个点距离各簇中心的距离（欧氏距离）
//        for (i = 0; i != K; i++) {
//            Data[k].distance[i] = 0;
//            for (j = 0; j < SIZE; j++) {
//                //欧式距离
//                Data[k].distance[i] += sqrt(
//                    (core[i][j] - Data[k].flower[j])
//                    * (core[i][j] - Data[k].flower[j]));
//                //曼哈顿距离
//            /*  Data[k].distance[i] += abs(center[i][j]-Data[k].feature[j]);*/
//            }
//        }
//        //寻找最小距离
//        float shortest = (Data[k].distance[0] < Data[k].distance[1])
//            ? Data[k].distance[0] : Data[k].distance[1];
//        shortest = (shortest < Data[k].distance[2])
//            ? shortest : Data[k].distance[2];
//        shortest = (shortest < Data[k].distance[3] ? shortest : Data[k].distance[3]);
//        for (i = 0; i < K; i++) {
//            if (Data[k].distance[i] == shortest) {
//                if (Data[k].pred == i) count++;
//                else Data[k].pred = i;
//            }
//        }
//    }
//    if (length == count) return OK;
//    else return ERROR;
//
//}
//
//void Kmeans::count_acc() {
//
//
//    int i, j, success = 0;
//    int length = Data.size();
//    //改变初始聚类中心选取方法后，以下key[]方法无需再使用
//    
//    int flower[K][K] = { 0 };
//   
//    for (i = 0; i != length; i++)
//    {
//        if (Data[i].ground == 0) {   //真实为0  看对应的是哪种，是因为随机性吗？看哪个最多
//            if (Data[i].pred == 0) flower[0][0]++;
//            if (Data[i].pred == 1) flower[0][1]++;
//            if (Data[i].pred == 2) flower[0][2]++;
//            if (Data[i].pred == 3) flower[0][3]++;
//        }
//        else if (Data[i].ground == 1) {
//            if (Data[i].pred == 0) flower[1][0]++;
//            if (Data[i].pred == 1) flower[1][1]++;
//            if (Data[i].pred == 2) flower[1][2]++;
//            if (Data[i].pred == 3) flower[1][3]++;
//        }
//        else if (Data[i].ground == 2) {
//            if (Data[i].pred == 0) flower[2][0]++;
//            if (Data[i].pred == 1) flower[2][1]++;
//            if (Data[i].pred == 2) flower[2][2]++;
//            if (Data[i].pred == 3) flower[2][3]++;
//        }
//        else if (Data[i].ground == 3) {
//            if (Data[i].pred == 0) flower[3][0]++;
//            if (Data[i].pred == 1) flower[3][1]++;
//            if (Data[i].pred == 2) flower[3][2]++;
//            if (Data[i].pred == 3) flower[3][3]++;
//        }
//       
//    }
//        for (i = 0; i != K; i++) {
//            if (flower[i][0] > flower[i][1] && flower[i][0] > flower[i][2] && flower[i][0] > flower[i][3])
//            	key[i] = 0;
//            else if (flower[i][1] > flower[i][0] && flower[i][1] > flower[i][2] && flower[i][1] > flower[i][3])
//            	key[i] = 1;
//            else if (flower[i][2] > flower[i][0] && flower[i][2] > flower[i][1] && flower[i][2] > flower[i][3])
//            	key[i] = 2;
//            else if (flower[i][3] > flower[i][0] && flower[i][3] > flower[i][1] && flower[i][3] > flower[i][2])
//            	key[i] = 3;
//            
//}
//    //如何通过flower[][]和key[]确定准确率？
//    //--flower[][]的行数表示聚类前的种类值（0，1，2），列数表示聚类后的值（0，1，2）；
//    //--key[]的列数代表聚类后的种类值,key[i]的值代表聚类前的值
//    //--当聚前为第一类花时，判断聚后的种类值i，在flower[0][i]的位置进行+1操作，然后比较第一行各列的数值，i列数值大就给key[i]赋第一类花对应的种类值，若第一列数值大则表示聚前聚后种类值相等的情况较多
//    //--当聚前为第二类花时，判断聚后的种类值i，在flower[1][i]的位置进行+1操作，然后比较第二行各列的数值，i列数值大就给key[i]赋第二类花对应的种类值，若第二列数值大则表示聚前聚后种类值相等的情况较多
//    //--当聚前为第三类花时，判断聚后的种类值i，在flower[2][i]的位置进行+1操作，然后比较第三行各列的数值，i列数值大就给key[i]赋第三类花对应的种类值，若第三列数值大则表示聚前聚后种类值相等的情况较多
//    for (j = 0; j != length; j++) {
//
//        if (Data[j].pred == key[Data[j].ground]) success++;
//    }
//    accuracy = (float)success / length;
//
//}
//
//void Kmeans::show(int condition, int generation) {
//
//    int length = Data.size();
//    int i, j;
//
//    for (i = 0; i != length; i++) {
//
//        for (j = 0; j != SIZE; j++) {
//
//            cout << "\t" << Data[i].flower[j];
//        }
//        cout << "\t" << Data[i].ground << "\t" << Data[i].pred << endl;
//    }
//
//    if (condition == OK) {
//        cout << "正常预测!" << endl;
//        cout << "共迭代 " << generation + 1 << " 次" << endl;
//        cout << "正确率 " << accuracy * 100 << "%";
//
//    }
//    if (condition == ERROR) {
//
//        cout << "预测失败" << endl;
//        cout << "正确率 " << accuracy * 100 << "%";
//    }
//}
////添加数据
//void Kmeans::addData()
//{
//    srand(static_cast<unsigned int>(time(nullptr))); // 使用当前时间作为种子
//   
//    //打开iris.txt以追加数据
//    ofstream irisFile("iris.txt", ios_base::app);
//    if (!irisFile.is_open())
//    {
//        cerr << "Open file failture" << endl;
//
//    }
//    //添加50行随机数据
//    const int num_rows = 50;
//    const char* non_iris = "Non_Iris";
//    for (int i = 0; i < num_rows; i++)
//    {
//        //生成四个随机浮点数
//        float floats[4];
//        for (int j = 0; j < 4; j++)
//        {
//            floats[j] = static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * 100.0f;
//        }
//        //格式化并写入数据集中
//        irisFile << fixed << setprecision(2) << floats[0] << ' '
//            << floats[1] << ' '
//            << floats[2] << ' '
//            << floats[3] << ' '
//            << non_iris << endl;
//
//    }
//    irisFile.close();
//}
//void Kmeans::text()
//{
//    int numT = 0;
//    int num = 0;
//    char choice = 'y';
//    while (choice == 'y')
//    {
//        num++;
//        float num1, num2, num3, num4;
//        int a1, a2;
//        cout << "请输入一组数据：" << endl;
//        cin >> num1 >> num2 >> num3 >> num4 >> a1;
//        int i, k, j;
//        //计算距离
//        float dis[4] = { 0 };
//        
//        for (int i = 0; i < 4; i++)
//        {
//            dis[i] = sqrt((core[i][0] - num1) * (core[i][0] - num1)) + sqrt((core[i][1] - num2) * (core[i][1] - num2)) + sqrt((core[i][2] - num3) * (core[i][2] - num3)) + sqrt((core[i][3] - num4) * (core[i][3] - num4));
//        }
//        int min = 0;
//        for (int i = 1; i < K; i++) {
//        	if (dis[i] < dis[min]) {
//        		min = i;
//        	}
//        }
//        for (int i = 0; i < K; i++)
//        {
//        	if (key[i] == min)
//        	{
//        		min = i;
//        		break;
//        	}
//        }
//      
//        //找最小距离
//        if (min == 0)
//        {
//            cout << "预测值：" << 0 << endl;
//            Mat img = imread("iris1.png");
//            namedWindow("第一类");
//            imshow("第一类", img);
//            waitKey(0);
//        }
//        if (min == 1)
//        {
//            cout << "预测值：" <<1 << endl;
//            Mat img = imread("iris2.png");
//            namedWindow("第二类");
//            imshow("第二类", img);
//            waitKey(0);
//        }
//
//        if (min == 2)
//        {
//            
//            cout << "预测值：" << 2 << endl;
//            Mat img = imread("iris3.png");
//            namedWindow("第三类");
//            imshow("第三类", img);
//            waitKey(0);
//        }
//
//        if (min==3)
//        {
//           
//            cout << "预测值：" << 3 << endl;
//            Mat img = imread("iris4.png");
//            namedWindow("非花类");
//            imshow("非花类", img);
//            waitKey(0);
//        }
//        if (min == a1)
//            numT++;
//        num++;
//        //若不将numT转化为float型，在进行运算时，会舍弃小数部分导致result结果总为0；
//        accuracy = ((float)(numT) / num) * 100;
//        cout << fixed << setprecision(2) << accuracy << "%" << endl;
//        accuracy = 0;
//        cout << "continue?y/n:";
//        cin >> choice;
//    }
//}
//void Kmeans::genstartcore() {
//    srand((int)time(NULL));
//    int length = Data.size();
//    int x = rand() % length;
//
//    // 将随机选择的第一个质心复制到core数组中
//    for (int j = 0; j < SIZE; j++) {
//        core[0][j] = Data[x].flower[j];
//    }
//    // 使用K-means++算法选择剩余的质心
//    for (int i = 1; i < K; i++) {
//        x = select(Data, core, i);
//        for (int j = 0; j < SIZE; j++) {
//            core[i][j] = Data[x].flower[j];
//        }
//    }
//}
//int Kmeans::select(const vector<dataset>& data, const float center[][SIZE], int k) {
//    int nextcen = -1;//下一个质心的下标
//    int length = data.size();
//
//    vector<float> mindis(length, 10000);//用于存储每个数据点到最近质心的距离的平方，初始值10000（一个大的数）
//    for (int i = 0; i < length; i++) {  // 计算每个数据点到最近质心的距离的平方
//        for (int j = 0; j < k; j++) {  //j代表已有几个初始点
//            float dis = 0.0;  //距离
//            for (int m = 0; m < SIZE; m++) {
//                dis += (data[i].flower[m] - center[j][m]) * (data[i].flower[m] - center[j][m]);
//            }
//            if (dis < mindis[i]) {
//                mindis[i] = dis;
//            }
//        }
//    }
//    // 选择下一个质心的索引，使用轮盘赌算法
//    vector<float> proba(length);//每个数据点作为下一个质心的概率
//
//    float total = 0;//计算所有数据到最近质心的距离的平方的和
//    for (int i = 0; i < length; i++)
//        total += mindis[i];
//    for (int i = 0; i < length; i++) {
//        proba[i] = mindis[i] / total;//计算每个数据点被选
//        //择为下一个质心的概率，按照其到最近质心的距离的平方与总和的比例计算。
//    }
//    float random = (float)(rand()) / RAND_MAX;//生成一个[0, 1)内的随机数，作为轮盘赌算法的随机比较值
//
//    float cal = 0.0;//记录累积的概率值
//    for (int i = 0; i < length; i++) {
//        //通过遍历数据集中的每个数据点，计算累积概率，并与random 进行比较。
//        cal += proba[i]; //在循环中，累加当前数据点的概率到累积概率中。
//        if (random - cal <= 1e-6) {
//            nextcen = i;
//            break;//当累积概率超过random时，就找到了下一个质心的索引i此时，将i赋值给 nextcen，并跳出循环。
//
//        }
//    }
//    return nextcen;
//}