# -*- coding: utf-8 -*-
"""
Created on Sun Mar 30 15:09:19 2025

@author: Kaden Sawyer
"""
_author_ = "Kaden Sawyer"
_credits_ = ["none"]
_email_ = "sawyerkd@mail.uc.edu"

"""
    n_estimators | Train Score  | Test Score  
    ----------------------------------------
    1            | 0.9132       | 0.7541      
    2            | 0.9174       | 0.7541      
    3            | 0.9711       | 0.7869      
    4            | 0.9545       | 0.7213      
    5            | 0.9669       | 0.7869      
    6            | 0.9793       | 0.8033      
    7            | 0.9793       | 0.8361      
    8            | 0.9959       | 0.8197      
    9            | 0.9917       | 0.8361      
    10           | 0.9959       | 0.8525      

    Best performance: n_estimators=10 with test score=0.8525



"""
import pandas as pd
import numpy as np
from sklearn.ensemble import RandomForestClassifier
from sklearn.model_selection import train_test_split

# load the dataset
heart_disease = pd.read_csv('heart.csv') 
X = heart_disease.drop(['target'], axis=1) 
Y = heart_disease['target']

# split data 
X_train, X_test, Y_train, Y_test = train_test_split(X, Y, test_size=0.2, random_state=42)

results = []

# test with n_estimators from 1 to 10
for n in range(1, 11):
    # create and train Random Forest classifier
    clf = RandomForestClassifier(n_estimators=n, random_state=42)
    clf.fit(X_train, Y_train)
    
    # computing scores
    train_score = clf.score(X_train, Y_train)
    test_score = clf.score(X_test, Y_test)
    
    results.append((n, train_score, test_score))

# printing the results in a table format
print(f"{'n_estimators':<12} | {'Train Score':<12} | {'Test Score':<12}")
print("-" * 40)
for n, train, test in results:
    print(f"{n:<12} | {train:<12.4f} | {test:<12.4f}")

# find and print best test score
best_n, best_train, best_test = max(results, key=lambda x: x[2])
print(f"\nBest performance: n_estimators={best_n} with test score={best_test:.4f}")

