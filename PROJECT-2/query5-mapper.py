#!/usr/bin/env python
 
import sys

for line in sys.stdin:
    try: 
        CustID="-1"
        CustName = "unknown" 
	CountryCode=5
        TransEmit = "0" 
         
   
        line = line.strip()
         
        splits = line.split(",")
         
        if len(splits[1]) > 8: 
            CustID = splits[0]
	    if len(splits[0])<5:
	    	for num in range(0,5-len(splits[0])):
		    CustID='0' + CustID
            CustName = splits[1]
	    CountryCode=int(splits[3])
        else: 
            CustID = splits[1]
	    if len(splits[1])<5:
	    	for num in range(0,5-len(splits[1])):
		    CustID='0' + CustID
            TransEmit = "1"
      	    CountryCode=5

        if CountryCode == 5:
            print '%s,%s,%s' % (CustID,CustName,TransEmit)
    except: 
        pass

