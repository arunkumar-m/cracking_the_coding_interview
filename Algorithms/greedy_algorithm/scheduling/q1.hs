module Main where

import Data.List
import Text.ParserCombinators.Parsec

-- data type defined here

data Job = Job Int Int -- Job weight length
instance Show Job where
  show (Job x y) = "[Job] " ++ "W: " ++ (show x) ++ " L: " ++ (show y) ++ " D: " ++ (show $ x - y)
instance Eq Job where
  (Job x1 y1) == (Job x2 y2) = (x1 == x2) && (y1 == y2)
instance Ord Job where
  (Job x1 y1) <= (Job x2 y2) = ((x1 - y1) < (x2 - y2)) || ((x1 - y1) == (x2 - y2) && x1 < x2)

schedule :: [Job] -> (Int, Int)
schedule jobs = foldl calc (0, 0) $ reverse $ sort jobs where
  calc (weighted_time, time) (Job w l) = (weighted_time + w * (time + l), time + l)

-- parse the input file

parseFile = many1 digit >> eol >> endBy line eol
line = do
  x <- many1 digit
  spaces
  y <- many1 digit
  return $ Job (read x) (read y)
eol = string "\n"


-- main

main = do
  putStrLn "A Scheduling Algorithm\nUsing weight - length as the metric"
  c <- readFile "jobs.txt"
  case parse parseFile "(file)" c of
    Left e -> do putStrLn "Error parsing input:"
                 print e
    Right r -> do
      -- mapM_ print r
      putStrLn "Result:"
      print $ schedule r
