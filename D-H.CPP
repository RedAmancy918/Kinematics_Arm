#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

// 定义一个结构来存储每个关节的DH参数
struct DHParameter {
    double theta; // 关节角度
    double d;     // 关节偏移
    double a;     // 连杆长度
    double alpha; // 连杆扭角
};

// 正运动学计算函数
void computeForwardKinematics(const std::vector<DHParameter>& parameters) {
    // 初始化单位矩阵
    std::vector<std::vector<double>> T = {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };

    for (const auto& param : parameters) {
        double theta_r = param.theta * M_PI / 180.0; // 转换为弧度
        double alpha_r = param.alpha * M_PI / 180.0; // 转换为弧度

        // DH 矩阵
        std::vector<std::vector<double>> A = {
            {cos(theta_r), -sin(theta_r)*cos(alpha_r),  sin(theta_r)*sin(alpha_r), param.a*cos(theta_r)},
            {sin(theta_r),  cos(theta_r)*cos(alpha_r), -cos(theta_r)*sin(alpha_r), param.a*sin(theta_r)},
            {0,             sin(alpha_r),              cos(alpha_r),              param.d},
            {0,             0,                         0,                         1}
        };

        // 矩阵乘法
        std::vector<std::vector<double>> T_new(4, std::vector<double>(4, 0));
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                for (int k = 0; k < 4; ++k) {
                    T_new[i][j] += T[i][k] * A[k][j];
                }
            }
        }
        T = T_new;
    }

    // 输出结果矩阵
    std::cout << "Transformation Matrix T from base to end effector is:" << std::endl;
    for (const auto& row : T) {
        for (double val : row) {
            std::cout << std::setw(10) << val << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int n;
    std::cout << "Enter the number of joints: ";
    std::cin >> n;

    std::vector<DHParameter> parameters(n);
    for (int i = 0; i < n; ++i) {
        std::cout << "Enter theta, d, a, alpha for joint " << i + 1 << ": ";
        std::cin >> parameters[i].theta >> parameters[i].d >> parameters[i].a >> parameters[i].alpha;
    }

    computeForwardKinematics(parameters);

    return 0;
}
