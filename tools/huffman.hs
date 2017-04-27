import qualified Data.Map as Map
import Data.Map(Map)
import Data.List
import Data.Maybe
    
    
type FrequencyMap a = Map a Integer

data Bit = Zero | One
    
data HuffmanTree a = Branch (HuffmanTree a) (HuffmanTree a) Integer
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
      add freqs x = Map.insert x (1 + Map.findWithDefault 0 x freqs) freqs


weight :: Eq a => HuffmanTree a -> Integer
------------------------------------------
weight (Leaf _ w)     = w
weight (Branch _ _ w) = w


branch :: Eq a => HuffmanTree a -> HuffmanTree a -> HuffmanTree a
-----------------------------------------------------------------
branch l r = Branch l r (weight l + weight r)


buildTree :: Eq a => FrequencyMap a -> HuffmanTree a
----------------------------------------------------
buildTree freqs = aux $ sort $ [ Leaf char freq | (char, freq) <- Map.toList freqs ]
    where
      aux [ x ]          = x
      aux (x : y : rest) = aux $ sort (branch x y : rest)


containsDuplicates :: Eq a => [a] -> Bool
-----------------------------------------
containsDuplicates xs = length xs /= length (nub xs)

                        
unambiguousTree :: Eq a => FrequencyMap a -> HuffmanTree a
----------------------------------------------------------
unambiguousTree freqs = aux $ sort [ Leaf char freq | (char, freq) <- Map.toList freqs ]
    where
      aux [ x ]          = x
      aux xs@(x : y : rest)
          | containsDuplicates (map weight xs)  = error "Ambiguity!"
          | otherwise                           = aux $ sort (branch x y : rest)
                           

codes :: Ord a => HuffmanTree a -> Map a [Bit]
----------------------------------------------
codes (Branch x y _) = Map.map (Zero:) (codes x) `Map.union` Map.map (One:) (codes y)
codes (Leaf x _)     = Map.fromList [ (x, []) ]


encode :: String -> [Bit]
-------------------------
encode str = concat [ fromJust $ Map.lookup c cs | c <- str ]
    where
      cs = codes $ unambiguousTree $ frequencies str
