# -*- coding: utf-8 -*-
"""
Created on Sat Apr  5 14:23:45 2025

@author: Kaden Sawyer
"""

_author_ = "Kaden Sawyer"
_credits_ = ["none"]
_email_ = "sawyerkd@mail.uc.edu"

import matplotlib.pyplot as plt
import pandas as pd
import numpy as np
from pandas import DataFrame, Series
sh_raw = pd.read_csv('dataset.csv', 
   header = None, 
   names = ['Year','Title','Comic','IMDB','RT','','OpeningWeekendBoxOffice','AvgTicketPriceThatYear','EstdOpeningAttendance','USPopThatYear'])

sh = sh_raw[np.isfinite(
          sh_raw.OpeningWeekendBoxOffice)]
print(sh.head(5))
"""Output
Year            Title  ... EstdOpeningAttendance  USPopThatYear
1  1978.0         Superman  ...           3190317.521    222584545.0
2  1980.0      Superman II  ...           5241830.112    227224681.0
4  1983.0     Superman III  ...           4238843.492    233791994.0
5  1984.0        Supergirl  ...           1707812.202    235824902.0
6  1986.0  Howard the Duck  ...           1366613.477    240132887.0

[5 rows x 10 columns]
"""

# Normalize and scatterplot the scores
imdb_normalized = sh.IMDB / 10         
sh.insert(10,'IMDBNormalized',imdb_normalized)
rt_normalized = sh.RT/100        
sh.insert(11, 'RTNormalized', rt_normalized)
sh.plot.scatter(x ='RTNormalized', y ='IMDBNormalized')
plt.show()

print(sh[['RTNormalized','IMDBNormalized']].corr())
print(sh[['RTNormalized','IMDBNormalized']].describe())

#deliverables
# all DC movies
print("\nAll DC movies:")
print(sh[sh.Comic == "DC"])

#year and title columns of all "DC" movies
print("\nAll DC movies year and title:")
print(sh.loc[sh.Comic == 'DC',['Year','Title']])


#year and title of all "Marvel" movies
print("\nAll Marvel movies year and title:")
print(sh.loc[sh.Comic == "Marvel",['Year','Title']])


#scatter plot of Year vs AvgTicketPriceThatYear
plt.scatter(sh.Year, sh.AvgTicketPriceThatYear)
plt.title('Average Ticket Price by Year')
plt.xlabel('Year')
plt.ylabel('Avg Ticket Price')
plt.grid(True)
plt.show()

#correlation between Year and AvgTicketPriceThatYear
print("\nCorrelation between Year and AvgTicketPriceThatYear:")
print(sh[['Year', 'AvgTicketPriceThatYear']].corr())


#summary statistics for OpeningWeekendBoxOffice
print("\nSummary statistics for OpeningWeekendBoxOffice:")
print(sh['OpeningWeekendBoxOffice'].describe())

