# 2048

## 项目简介
本项目旨在 C++ 控制台实现 2048 小游戏。

TA 提供模板文件即为 `2048.cpp`，小游戏核心实现文件为 `core.cpp`。

核心亮点：**代码简洁**，对四个方向的等价移动通过转置、翻转来等效，减小代码量。

## 目录结构

```
├── 2048.sln // Visual Studio 解决方案文件 
|
├── README.md
|
├── 2048.cpp // 主程序入口
|
├── core.h // 小游戏实现核心组件
└── core.cpp // 小游戏实现核心
```
## 编译与运行

### 环境要求
- **开发环境**：Visual Studio（推荐使用 VS2022），或其他支持 C++ 的 IDE。
- **操作系统**：Windows，使用 `_getch()` 实现无回车输入。

### 编译步骤
1. 将所有源代码和图像文件放置在同一工作目录下，按照上面的目录结构组织文件。  
2. 在 Visual Studio 中打开 `2048.sln` 。  
3. 编译并运行项目。  
4. 根据提示在主菜单选择相应功能进行测试。

## 核心实现函数

```C++
void init_board(int board[4][4]); // 初始化游戏盘面
void add_random_tile(int board[4][4]); // 每轮随机生成小数
bool can_move(int board[4][4]); // 判断是否可以移动
bool move_left(int board[4][4], int& score); //向左移动
bool move_right(int board[4][4], int& score);
bool move_up(int board[4][4], int& score);
bool move_down(int board[4][4], int& score);
```

## 贡献指南

欢迎提交 Issue 和 Pull Request。

## 许可证

MIT License