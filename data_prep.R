setwd("~/Documents/TOP/MY CPP PACKAGES/parsing-exercise/")

library(magrittr)

n <- 10

temperature <- rnorm(n) %>% as.character 

set.seed(1234)
station <- c("aaaaaaa", "b", "c") %>% sample(n, replace = TRUE) 

c("efef", "", "er;;;;") %>% 
  c(paste(station, temperature, sep = ";")) %>% 
  c("efrfr;fr;rfrgfr;gr", "", "a") %>% 
  writeLines("data/stations.csv")



