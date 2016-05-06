import qualified Data.Map as Map
import Data.Map(Map)
import Data.List
import Data.Maybe
    
    
type FrequencyMap a = Map a Integer

data Bit = Zero | One
    
data HuffmanTree a = Branch (HuffmanTree a) (HuffmanTree a)
                   | Leaf a Integer
                     deriving (Eq, Show)
                     

instance Show Bit where
    show Zero = "0"
    show One  = "1"
                              
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
weight (Leaf _ w)          = w
weight (Branch left right) = weight left + weight right


buildTree :: Eq a => FrequencyMap a -> HuffmanTree a
----------------------------------------------------
buildTree freqs = aux $ sort $ [ Leaf char freq | (char, freq) <- Map.toList freqs ]
    where
      aux [ x ]          = x
      aux (x : y : rest) = aux $ sort (Branch x y : rest)


codes :: Ord a => HuffmanTree a -> Map a [Bit]
----------------------------------------------
codes (Branch x y) = Map.map (Zero:) (codes x) `Map.union` Map.map (One:) (codes y)
codes (Leaf x _)   = Map.fromList [ (x, []) ]


encode :: String -> [Bit]
-------------------------
encode str = concat [ fromJust $ Map.lookup c cs | c <- str ]
    where
      cs = codes $ buildTree $ frequencies str
