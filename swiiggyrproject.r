



    library(dplyr)
    setwd("D:/rfiles")
    data<-read.csv('swiggy.csv')    
    data

    subdata<-select(data,DE_HOME_LAT,DE_HOME_LNG,DE_JOINING_DATE) 
    subdata
    dim(data)
    summary(data)
    summary(subdata)
    subdata<-filter(subdata,DE_HOME_LNG>72.90321 &DE_HOME_LNG<72.93086)
    subdata
    subdata<-arrange(subdata,desc(DE_HOME_LAT))
    subdata  
    
    
    table(subdata)
    hist(subdata,col='red')
    data
    
    
    
    head(subdata,3)
    subdata<-1:10
    subdata
    
    
    subdata<-filter(subdata,DE_ZONE_ID > 372 & DE_ZONE_ID < 841)
    class(subdata)
    
    
    
    

    
    
    
    
    
    
    
    
    
    
    
    library(dplyr)
    setwd("D:rfiles")    
    data<-read.csv('swiggy.csv')    
    data    
    