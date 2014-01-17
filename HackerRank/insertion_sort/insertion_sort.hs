module Main where

-- empty list: returns empty
-- otherwise: insert head into a sorted list
insertionsort :: (a -> a -> Bool) -> [a] -> [a]
insertionsort pred [] = []
insertionsort pred (x:xs) = insert pred x (insertionsort pred xs)

-- insert element x into []: return [x]
-- insert element x into (y:ys)
-- if pred x y is true, then insert x in the front
-- otherwise: insert it into ys and set y as the head
insert :: (a -> a -> Bool) -> a -> [a] -> [a]
insert pred x [] = [x]
insert pred x (y:ys)
  | pred x y = (x:y:ys)
  | otherwise = y:(insert pred x ys)

main = do
  let l = insertionsort (<=) [1,5,6,4,3]
  print l

