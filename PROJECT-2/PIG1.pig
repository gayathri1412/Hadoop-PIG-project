A = LOAD '/home/trans.txt' USING PigStorage(',') AS (TransID,CustID,TransTotal,TransNumItems,TransDesc);
B = GROUP A BY CustID;
C = FOREACH B GENERATE group, COUNT(A.TransID), SUM(A.TransTotal);
STORE C INTO '/user/out2';
