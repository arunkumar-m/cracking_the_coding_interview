-- Read input from STDIN. Print output to STDOUT

module Main where

import Data.Map (Map)
import qualified Data.Map as M

-- Note:
-- insertWith f key value mp will insert (key, value) into mp if key does 
-- not exist in the map. if the key does exist, will insert (key, f new old)

readInt :: String -> Int
readInt line = read line

readArr :: String -> [Int]
readArr line = map read $ words line

count :: [Int] -> Map Int Int
count arr = foldl cnt M.empty arr where
  cnt m i = M.insertWith f i 1 m where
  f new old = old + 1

lonelyint :: Map Int Int -> Int
lonelyint m = fst $ (M.toList (M.filter ((==) 1) m)) !! 0

main = do
  line1 <- getLine
  line2 <- getLine
  let n = readInt line1
      arr = readArr line2
  let m = count arr
      ret = lonelyint m
  print ret
