# -*- coding: utf-8 -*-
"""
Created on Mon Apr 14 12:45:36 2025

@author: Kaden Sawyer
"""

_author_ = "Kaden Sawyer"
_credits_ = ["none"]
_email_ = "sawyerkd@mail.uc.edu"


""" output table:
    Multiple Linear Regression using All features
    R2 score: 0.600898
    MSE score: 0.535015

    Feature 0 (MedInc) has R2 score: 0.463081
              has MSE score: 0.719766
    Feature 1 (HouseAge) has R2 score: 0.013186
              has MSE score: 1.322872
    Feature 2 (AveRooms) has R2 score: 0.024105
              has MSE score: 1.308234
    Feature 3 (AveBedrms) has R2 score: -0.001127
              has MSE score: 1.342058
    Feature 4 (Population) has R2 score: 0.000085
              has MSE score: 1.340434
    Feature 5 (AveOccup) has R2 score: -0.000183
              has MSE score: 1.340794
    Feature 6 (Latitude) has R2 score: 0.020369
              has MSE score: 1.313243
    Feature 7 (Longitude) has R2 score: 0.001484
              has MSE score: 1.338559
    Short explanation:
The Multiple linear regression using all features achieved the best performance 
with an R² score of 0.600898 and an MSE of 0.535015, 
this confirmed that combining features improves prediction accuracy.
Among the single-feature models, Median Income (MedInc) was the 
strongest predictor with an R² score of 0.463081 and an MSE of 0.719766. 
All other features performed worse, with near-zero or negative R² scores.
This shows that while some features may be useful on their own, 
using all features together results in a much better model.

"""

import pandas as pd
from sklearn.datasets import fetch_california_housing
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.metrics import r2_score, mean_squared_error
import matplotlib.pyplot as plt
import seaborn as sns

# load dataset and prepare DataFrame
cali = fetch_california_housing()
cali_df = pd.DataFrame(cali.data, columns=cali.feature_names)
cali_df['MedHouseValue'] = pd.Series(cali.target)

# multiple Linear Regression
X_train, X_test, y_train, y_test = train_test_split(cali.data, cali.target, random_state=11)
mu_regress = LinearRegression()
mu_regress.fit(X=X_train, y=y_train)
predicted = mu_regress.predict(X_test)

# calculate metrics for multiple regression
mlr_r2 = r2_score(y_test, predicted)
mlr_mse = mean_squared_error(y_test, predicted)

print("Multiple Linear Regression using All features")
print(f"R2 score: {mlr_r2:.6f}")
print(f"MSE score: {mlr_mse:.6f}\n")

# linear Regression for each feature
for i, feature in enumerate(cali.feature_names):
    # extract single feature
    X_single = cali_df[[feature]].values
    
    # split the  data
    X_train, X_test, y_train, y_test = train_test_split(X_single, cali.target, random_state=11)
    
    # train model
    slr = LinearRegression()
    slr.fit(X_train, y_train)
    y_pred = slr.predict(X_test)
    
    # calculate metrics
    r2 = r2_score(y_test, y_pred)
    mse = mean_squared_error(y_test, y_pred)
    
    print(f"Feature {i} ({feature}) has R2 score: {r2:.6f}")
    print(f"          has MSE score: {mse:.6f}")

# visualization for multiple regression 
df = pd.DataFrame()
df['Expected'] = pd.Series(y_test)
df['Predicted'] = pd.Series(predicted)

figure = plt.figure(figsize=(9, 9))
axes = sns.scatterplot(data=df, x='Expected', y='Predicted')

start = min(y_test.min(), predicted.min())
end = max(y_test.max(), predicted.max())
axes.set_xlim(start, end)
axes.set_ylim(start, end)
line = plt.plot([start, end], [start, end], 'k--')
plt.title('Multiple Linear Regression: Expected vs Predicted Prices')
plt.show()



