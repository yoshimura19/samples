#coding:utf-8

import pandas as pd
import numpy as np
#import re

panel = pd.read_csv("h26-17cross3_full.csv")  #utfに変換済み
#utfに変換でずれるため、kubun,ken,shiを予め落とす
#nkf -w --overwrite h26-17cross3_full.csv

print(panel.columns)

#Index(['total_id', 'id', 'old_id', 'year', 'kubun', 'ken', 'shi', 'name','doctor', 'nurse', 'total_stuff', 'salary_doctor', 'allowance_doctor','ave_old_doctor', 'ave_serve_doctor', 'salary_nurse', 'allowance_nurse','ave_old_nurse', 'ave_serve_nurse', 'general_beds', 'total_beds','use_rates_general', 'ave_stays_general', 'ave_inpatient_per1day','ave_outpatient_per1day', 'inpatients_per1doctor','outpatients_per1doctor', 'inpatients_per1nurse','outpatients_per1nurse', 'medical_fee_per1inpatient','medical_fee_per1outpatient', 'medical_fee_per1doctor','medical_fee_per1nurse', 'inspections_per100patients','fixed_assets_per1bed', 'medical_revenue', 'non_medical_revenue','medical_cost_per1day1man', 'medical_cost', 'non_medical_cost','extraordinary_loss', 'Geographical_conditions', 'areas_facility','announcement_emergency_hospital', 'announced_beds_emergency_h','DPCdummy', 'kyu-H25', 'ruisekiDPC']

#idが各年ごとの病院の通し番号

year_for_y = 26   #分析年度
year_for_x = 26 - 3

#panel = panel.drop("shi", axis=1)   #空白で読み込みがずれるため
df_data_x = panel[panel.year == year_for_x]
df_data_x.drop("DPCdummy", axis=1)

for_y_dummy = panel.DPCdummy[panel.year == year_for_y]
before_y_dummy = panel.DPCdummy[panel.year == (year_for_y - 1)]

#df_DPC = pd.concat([panel.DPCdummy[panel.year == year_for_y], panel.DPCdummy[panel.year == (year_for_y - 1)]], axis=1)
#df_DPC.to_csv("test_DPC.csv")

panel_xy = pd.concat([df_data_x, for_y_dummy, before_y_dummy], axis=1)
print(panel_xy)
panel_xy.to_csv("test.csv")
