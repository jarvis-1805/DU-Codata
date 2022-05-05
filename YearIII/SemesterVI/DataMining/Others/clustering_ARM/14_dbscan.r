#DBSCAN
#install.packages("fpc")
library(fpc)
iris2 <- iris[-5] # remove class tags
ds <- dbscan(iris2, eps=0.45, MinPts=5)
 # compare clusters with original class labels
  ds
str(ds)
ds$cluster
table(ds$cluster, iris$Species) #cluster 0 indicates noise/outliers
plot(ds, iris2) #plots all attribute combination (one vs other) for 4 clusters


plot(ds, iris2[c(1,4)]) #plotting two features distribution clusterwise

#other values of parameters

ds1 <- dbscan(iris2, eps=0.40, MinPts=5)
ds1$cluster
table(ds1$cluster, iris$Species) #cluster 0 indicates noise/outliers
plot(ds1, iris2) #plots all attribute combination (one vs other) for 4 clusters


plot(ds1, iris2[c(1,4)]) #plotting two features distribution clusterwise
