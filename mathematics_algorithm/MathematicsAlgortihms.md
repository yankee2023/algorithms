# 目的

書籍書籍「[問題解決のための「アルゴリズム数学」が基礎からしっかり身につく本](https://www.amazon.co.jp/%E5%95%8F%E9%A1%8C%E8%A7%A3%E6%B1%BA%E3%81%AE%E3%81%9F%E3%82%81%E3%81%AE%E3%80%8C%E3%82%A2%E3%83%AB%E3%82%B4%E3%83%AA%E3%82%BA%E3%83%A0%C3%97%E6%95%B0%E5%AD%A6%E3%80%8D%E3%81%8C%E5%9F%BA%E7%A4%8E%E3%81%8B%E3%82%89%E3%81%97%E3%81%A3%E3%81%8B%E3%82%8A%E8%BA%AB%E3%81%AB%E3%81%A4%E3%81%8F%E6%9C%AC-%E7%B1%B3%E7%94%B0-%E5%84%AA%E5%B3%BB/dp/4297125218/ref=sr_1_44?adgrpid=87728018825&gclid=CjwKCAiAhJWsBhAaEiwAmrNyqypc71PaGxBBxuY1PcBqOFBxR6ZpmdtbaxxkYTkGZDsg_y3dhiykJxoCCwUQAvD_BwE&hvadid=651359515152&hvdev=c&hvlocphy=9171847&hvnetw=g&hvqmt=e&hvrand=10974612332950559041&hvtargid=kwd-370392273358&hydadcr=5743_13319654&jp-ad-ap=0&keywords=%E3%82%A2%E3%83%AB%E3%82%B4%E3%83%AA%E3%82%BA%E3%83%A0+%E3%81%A8+%E3%83%87%E3%83%BC%E3%82%BF%E6%A7%8B%E9%80%A0&qid=1703310329&sr=8-44)」の修行。

## リポジトリ
著書のリポジトリへのリンクは以下である。  
https://github.com/E869120/math-algorithm-book

## 自動採点システム  

書籍では自動採点システムとしてAtCoderを使用している。  
https://atcoder.jp/contests/math-and-algorithm

# 数学

## フィボナッチ数列  
以下の漸化式で定義される数列のこと。
``` @フィボナッチ数列
F1 = 1,
F2 = 2,
Fn = Fn-1 + Fn-2 (n >= 3)
```

# アルゴリズム

## 動的計画法(DP: Dynamic Programming)

与えられた問題を一連の部分問題に分解し、各部分問題に対する解を使って大きな部分問題へと準二階を求めていく手法。