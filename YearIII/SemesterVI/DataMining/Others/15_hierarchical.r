#hierarchical clustering
?hclust

View(iris)

id1 <- sample(1:dim(iris)[1], 30) #taking 30 observations
View(id1)

irisSample <- iris[id1,]  #extracting those 30 points
View(irisSample)

irisSample$Species <- NULL
View(irisSample)

hc <- hclust(dist(irisSample), method="ave") #ave,single
#hc <- hclust(dist(irisSample), method="single") #ave,single
plot(hc, hang = -1, labels=iris$Species[id1])

# cut tree into 4 clusters
rect.hclust(hc, k=4)

groups <- cutree(hc, k=4) #store observation placement in cluster
groups
View(groups)