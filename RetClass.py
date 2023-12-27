
class Rectangles:
    x=0
    y=0
    w=0
    h=0
    name="name"
    
    def __init__(self,x,y,w,h,retname):
        self.x = x
        self.y = y
        self.w = w
        self.h = h
        self.name = retname
        
    def origin(self):
        return [self.x,self.y]
        
    def w(self):
        return self.w
        
    def h(self):
        return self.h
        
        
    def getRectPointsX(self):
        return list([self.x,self.x+self.w,self.x+self.w,self.x,self.x])
    def getRectPointsY(self):
        return list([self.y,self.y,self.y-self.h,self.y-self.h,self.y])
        
    def IntersectionWith(self,ret):
    
        if(ret.name != self.name):
            retpointsx = ret.getRectPointsX()
            retpointsy = ret.getRectPointsY()
        
            for i in range(0,len(retpointsx)):
                if((retpointsx[i]>=self.x and retpointsx[i]<=self.x+self.w) and (retpointsy[i]<=self.y and retpointsy[i]>=self.y-self.h)): return True
            
            
            retpointsx = self.getRectPointsX()
            retpointsy = self.getRectPointsY()
        
            for i in range(0,len(retpointsx)):
                if((retpointsx[i]>=ret.x and retpointsx[i]<=ret.x+ret.w) and (retpointsy[i]<=ret.y and retpointsy[i]>=ret.y-ret.h)): return True
        
        return False