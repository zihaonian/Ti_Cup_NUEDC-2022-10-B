## 项目概述

​		本项目基于数学建模比赛，旨在解决市场交易员面临的三个关键问题。通过深入分析股票数据的大规模、非平稳的特征，我们提出了一种创新的解决方案，涉及循环神经网络模型（RNN）、长短时记忆神经网络模型（LSTM）、注意力模型、贪心算法和动态规划等技术。

## 文件结构

```
MCM/
│
├── 2022_MCM_ICM_Problems/         # 存放数学建模比赛题目，按问题划分
│   ├── 2022_MCM_Problem_A.pdf
│   ├── 2022_MCM_Problem_B.pdf
│   ├── 2022_MCM_Problem_C.pdf
│   ├── 2022_ICM_Problem_D.pdf
│   ├── 2022_ICM_Problem_E.pdf
│   └── 2022_ICM_Problem_F.pdf
│
├── 2022_Problem_C_DATA/           # 存放使用的数据集
│   ├── BCHAIN-MKPRU.csv
│   └── LBMA-GOLD.csv
│
├── formula/                       # 存放基于使用的公式
│   └── formula_Summary.docx
│
├── paper_chart/                   # 包含论文中图表
│   ├── Bitcoin Forecast Price Chart.opju
│   ├── CBAM network structure diagram.vsdx
│   ├── Degree of impact of single stock commission changes on final returns.opju
│   ├── Gold Forecast Price Chart.opju
│   ├── Indicative diagram of operation without holding assets (left) and holding assets(right).vsdx
│   ├── LSTM network structure expansion diagram.vsdx
│   ├── Prediction model mind map.vsdx
│   └── Problem 1 solving flow chart.vsdx
│
├── paper/                        # 包含完整的论文文本
│   ├── Trading strategy based on LSTM-RNN-CBAM model and .docx     
│   └── Trading strategy based on LSTM-RNN-CBAM model and .pdf
│
├── result/                  	  # 存放基于模型的计算结果
│   ├── Bitcoin time to date.xlsx
│   ├── Deviation rate - average price list.xlsx
│   ├── Gold-Bitcoin-Gold Trading Daily Chart.xlsx
│   ├── Normalization.xlsx
│   ├── Prime Time to Date.xlsx
│   ├── result.xlsx
│   └── Summary.xlsx
│
└── README.md                    # 本文档，提供有关问题描述、论文摘要以及文件结构等信息
```



## 问题一：时间序列预测与关键性因素提取

### 方法

1. 引入循环神经网络模型，但发现无法解决长时间的预测问题。
2. 加入LSTM神经网络模型，调整时间步长为20，用前20天的数据作为输入，第21天的收盘价格作为标签进行训练。
3. 引入注意力模型，通过卷积模块生成各个影响因素的特征图，计算权重图，将二者相乘获得关键性信息的位置。

### 结果

- 预测黄金价格误差为1.85%，比特币价格误差为3.08%。

## 问题二：投资组合优化

### 方法

1. 基于局部最优使用贪心算法建立转买策略，重新分配已购买的资产数量，增加的收益弥补佣金。
2. 基于全局最优使用动态规划建立分配策略，以购入资产的资金作为决策变量，以最大持有本金为目标函数，约束条件为投资金额不能超过持有本金和价格稳定程度。

### 结果

- 通过局部和全局最优获得最佳投资策略。

## 问题三：交易策略的敏感性分析

### 方法

1. 引入扰动参数k量化佣金率的波动。
2. 绘制3D直方图和计算均方差对比新旧交易策略。

### 结果

- 决策模型对佣金率的改变敏感程度不高，可以承受市场在一定范围内的波动，对比特币佣金率的改变的敏感程度更高。

## 论文摘要

·	For the first problem: a recurrent neural network model was first introduced to solve the potential problems of the stock having large amount of data, ambiguous information, non-linearity, and non-smoothness. But it was found that the long-time prediction problem could not be solved by this model. We then added LSTM neural network model to solve the long time series issue. We continuously adjusted the time step during the training process, and finally set the time step to 20. We used the data from the first 20 days as the input layer of the neural unit and the closing price on the 21st day as the label for training the model. Lastly, to extract the key factors from the many factors that affect the stock market changes, we introduced the attention model. The model first uses the convolution module to generate the feature map of each influencing factor, then calculates the weight map of the feature map from the channel and space, and finally multiplies the two maps to obtain the location of the key information and increase the weight of such information in the prediction process. The gold price predicted by the above method differs from the actual price by only 1.85% and the price of bitcoin differs only 3.08% from the actual.

​	Then, based on the predicted future prices, a yield function is constructed to quantify the buying and selling criteria to develop a buy-hold-sell strategy. The relative strength index (RSI) is then introduced to determine the risk level of the investment and the amount of each asset to buy. The above strategies, asset holdings, and RSI model are used to determine the constraints and construct the RSI dynamic programming model with the maximum net return as the objective function. This has resulted in a total value of $25,316.85 for the assets owned on September 11, 2021.

​	For the second problem: first, a rebuy strategy is built based on the local optimum using a greedy algorithm. The strategy is a reallocation of the quantity of bitcoins and gold that has been previously purchased, with the requirement that after the allocation the return is not only higher than the original return but also makes up for the commission paid, otherwise the original quantity state remains unchanged. Then, the allocation strategy is established based on the global optimum using dynamic programming, with the amount used to purchase bitcoin and gold as the decision variables, the maximum holding principal as the objective function, and the maximum return with the constraint that the investment amount cannot exceed the holding principal and the stability of the stock market. The whole transaction is used to obtain the best investment strategy by local and global optimality.

​	For the third problem: the volatility of the commission rate is specifically quantified by introducing a perturbation parameter k. The old and new trading strategies are compared by plotting a 3D histogram and calculating the mean squared deviation.

​	It is concluded that the decision model is not very sensitive to changes in commission rates and can withstand market fluctuations within a certain range. The decision model is more sensitive to changes in bitcoin commission rates, and it is important to pay attention to changes in bitcoin commission rates during the trading process.

**Keywords:** **LSTM-RNN-CBAM hybrid model RSI** **dynamic programming greedy strategy**
