import qualified Data.Map as Map
import Data.Map(Map)
import Data.List

    
type FrequencyMap a = Map a Integer

data HuffmanTree a = Branch (HuffmanTree a) (HuffmanTree a)
                   | Datum a Integer
                     deriving (Eq, Show)
                     

instance Eq a => Ord (HuffmanTree a) where
    x `compare` y = weight x `compare` weight y


frequencies :: Ord a => [a] -> FrequencyMap a
---------------------------------------------
frequencies = foldl add Map.empty
    where
      add freqs x = Map.insert x (case Map.lookup x freqs of
                                    Just n  -> n + 1
                                    Nothing -> 1) freqs


weight :: Eq a => HuffmanTree a -> Integer
------------------------------------------
weight (Datum _ w)         = w
weight (Branch left right) = weight left + weight right


buildTree :: Eq a => FrequencyMap a -> HuffmanTree a
----------------------------------------------------
buildTree freqs = aux $ sort $ [ Datum char freq | (char, freq) <- Map.toList freqs ]
    where
      aux [ x ]          = x
      aux (x : y : rest) = aux $ sort (Branch x y : rest)


                           
