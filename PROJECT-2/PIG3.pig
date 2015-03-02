A = LOAD '/home/cus' USING PigStorage(',') AS (ID,Name,Age,CountryCode,Salary);
B = LOAD '/home/trans.txt' USING PigStorage(',') AS (TransID,CustID,TransTotal,TransNumItems,TransDesc);
C = FOREACH (JOIN A BY ID,B BY CustID parallel 40) GENERATE B::CustID as c1,A::CountryCode as cc1,B::TransTotal as t1;
D = GROUP C BY (cc1);
E = FOREACH D {
     aleph = C.c1;
     beth = distinct aleph;
     GENERATE FLATTEN(group) as (cc1), COUNT(beth),MIN(C.t1), MAX(C.t1);
     }
STORE E INTO '/user/out10';

