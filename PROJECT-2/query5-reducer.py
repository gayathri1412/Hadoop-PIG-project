#!/usr/bin/env python
  
import sys
  
Trans2Count = {}
ID2Name = {}


for line in sys.stdin:
    
    line = line.strip()
     
    try:
        
        CustID,CustName,TransEmit = line.split(',')
	
	if TransEmit == "0":
	    ID2Name[CustID]=CustName
	    continue 

	try:
            TransEmit = int(TransEmit)
    	except ValueError:
            continue
	try:
            Trans2Count[CustID]=Trans2Count[CustID]+TransEmit
	except:
            Trans2Count[CustID] = TransEmit

    except:
        pass
 
for CustID in Trans2Count.keys():
    try:
        print '%s\t%s, %s'% ( CustID,ID2Name[CustID],str(Trans2Count[CustID]))
    except:
        pass
 
