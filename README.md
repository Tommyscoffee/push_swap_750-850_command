# push_swap_750-850_command
this is 42tokyo's subject which sort arguments only with 6 commands.


[usage]
１：makeコマンドを実行してください。
２：シェルスクリプトがありますので、"./exec.sh [引数の数]"と実行すると、勝手にソートしてくれて、実行したコマンドは表示され、最後に緑色で実行したコマンドの手数が表示されます。
引数はそれぞれ”-100 ~ 21000000"のランダムの数字です。
文字この範囲を変更したいのであれば、exec.shファイルの3行目の$1以降の２つの整数を変更してください。

この課題は、２つのスタックA,Bを用意し、6つのコマンドでソートしていくものです。

[sa]  スタックAの一番上と二番目を入れ替えます。
[ra]  スタックAを一番上が一番下に来るように回転させます。
[rra] raの逆バージョンです。

[sb]  saのスタックBバージョン
[rb]  raのスタックBバージョン
[rrb] rbの逆バージョン

[visualizer]

<img width="606" alt="スクリーンショット 2022-06-01 21 19 54" src="https://user-images.githubusercontent.com/67151024/171403188-c09a33b2-6f73-4d00-89ce-65160ecb5165.png">
もし、実際にコマンドごとにスタックがどのように変化して行っているのかを確認したい場合は、ビジュアライザーを用意したのでそれをご利用ください。
ご利用方法は、src/operation/command_a.c, command_b.cファイルのvisualizerというコメントがある箇所のコメントアウトを外すだけです。（アナログな方法ですみません）

[アルゴリズム]
主にクイックソートを使いました。最適化やアレンジしたので普通ものもとは異なるので似非クイックソートです。

[手数]
手数ですが、引数が100この時(つまり"./exec.sh 100"の時)大体750手数くらいですが、誤差が120くらいあるので、何回かしてみてください。

<img width="1195" alt="スクリーンショット 2022-06-01 21 31 42" src="https://user-images.githubusercontent.com/67151024/171405108-2643280e-590b-4b21-8c65-917d8feac4fd.png">

