#hierarchical clustering
id1 <- sample(1:dim(iris)[1], 30) #taking 30 observations
id1
irisSample <- iris[id1,]  #extracting those 30 points
irisSample$Species <- NULL
irisSample
hc <- hclust(dist(irisSample), method="ave") #ave,single
plot(hc, hang = -1, labels=iris$Species[id1])
# cut tree into 4 clusters
rect.hclust(hc, k=4)
groups <- cutree(hc, k=4) #store observation placement in cluster
groups

?hclust
