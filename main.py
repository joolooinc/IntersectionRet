import numpy as np
import matplotlib.pyplot as plt
import sys
import matplotlib.pyplot as plt

import RetClass


if __name__ == "__main__":

    
    RectLists = []
    
    
    for i in range(1,len(sys.argv)):
    
        f = open(sys.argv[i],"r")
        
        fcontent = f.readline()
        
        content = [float(x) for x in fcontent.split(' ')]
        
        
        ret = RetClass.Rectangles(content[0],content[1],content[2],content[3],"ret"+str(i))
        
        RectLists.append(ret)
        
        f.close()
        
       
    
    
    #Analize Intersection
    
    for ret in RectLists:
    
        print("\n\n+++++++++++++++++")
        print(ret.name+" Intersections: \n")
    
        for i in range(0,len(RectLists)):
            if(ret.IntersectionWith(RectLists[i])): print(RectLists[i].name)
        
        print("+++++++++++++++++\n")
    
    
    #Plot rectangles
    
    fig,ax = plt.subplots()
    
    for x in RectLists:
        plt.plot(x.getRectPointsX(),x.getRectPointsY(),label=x.name)

    plt.legend()
    plt.show()
