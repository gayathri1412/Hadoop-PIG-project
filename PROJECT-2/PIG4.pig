A = LOAD '/home/cust.txt' USING PigStorage(',') AS (ID,Name,Age,CountryCode,Salary);
B = LOAD '/home/trans.txt' USING PigStorage(',') AS (TransID,CustID,TransTotal,TransNumItems,TransDesc);
C = FOREACH (JOIN A BY ID,B BY CustID USING 'replicated') GENERATE B::CustID as c1,A::Name as n1,A::Salary as s1,B::TransID as t1, B::TransTotal as t2, B::TransNumItems as t3;
D = GROUP C BY (c1,n1,s1);
E = FOREACH D GENERATE FLATTEN(group) as (c1,n1,s1), COUNT(C.t1), SUM(C.t2), MIN(C.t3);
STORE E INTO '/user/out11'; 
