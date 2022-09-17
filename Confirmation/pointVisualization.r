mydata <- read.csv("points.txt")
colnames(mydata)
nrow(mydata)
nums <- 88000
plot(seq(1, nums, 1), head(mydata$X0, nums), col = "black", type="b")
plot(seq(1, 484000, 100), mydata$X0[seq(1, 484000, 100)], col = "black", type="b")
getwd()
