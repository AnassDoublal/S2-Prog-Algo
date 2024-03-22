<!DOCTYPE html>
<html>
<body>
  <h1>Ne garder que le vert</h1>
  <p>&nbsp; &nbsp; &nbsp;&nbsp;</p>
  <p><img alt="image6" src="images/image6.png"><img alt="image12" src="images/image12.png"></p>
  <p>La fonction vert manipule une image en réduisant les composantes rouge et bleue de chaque pixel à zéro pour créer une version où seule le vert est présent.</p>
  <h1>Échanger les canaux</h1>
  <p>&nbsp; &nbsp; &nbsp;</p>
  <p><img alt="image6" src="images/image6.png"><img alt="image28" src="images/image28.png"></p>
  <p>La fonction "canaux" opère sur une image en utilisant une variable temp pour échanger les valeurs des canaux rouge et bleu pour chaque pixel, puis sauvegarde l'image modifiée en format PNG dans un répertoire de sortie spécifié.</p>
  <h1>Noir & Blanc</h1>
  <p><img alt="image6" src="images/image6.png"><img alt="image4" src="images/image4.png"></p>
  <p>On utilise la moyenne des trois couleurs RGB pour donner une image en noir et blanc.</p>
  <h1>Négatif</h1>
  <p>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;</p>
  <p><img alt="image6" src="images/image6.png"><img alt="image15" src="images/image15.png"></p>
  <p>La fonction “négatif” prend l’inverse de chaque composante r, g, b des couleurs de notre image.</p>
  <h1>Dégradé</h1>
  <h1><img alt="image26" src="images/image26.png"></h1>
  <p>On divise nos couleurs par la largeur de l’image.</p>
  <h1>Miroir</h1>
  <p><img alt="image21" src="images/image21.png"><img alt="image6" src="images/image6.png"></p>
  <p>Il faut s’assurer de copier l’image avant d’appliquer le miroir, pour éviter de manipuler des pixels déjà manipulés en parcourant l’image.</p>
  <h1>Image bruitée</h1>
  <p><img alt="image6" src="images/image6.png"><img alt="image9" src="images/image9.png"></p>
  <p>On change la couleur d’un pixel sur 7. Pour chaque pixel modifié, on lui génère une couleur aléatoire.</p>
  <h1>Rotation de 90°</h1>
  <p><img alt="image5" src="images/image5.png"><img alt="image6" src="images/image6.png"></p>
  <p>Après avoir créé une image avec de nouvelles dimensions, on inverse les coordonnées x et y. Pour obtenir une rotation dans le sens des aiguilles d’une montre au lieu de l’inverse, on applique un miroir horizontal sur la coordonnée x.</p>
  <h1>RGB split</h1>
  <p>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; <img alt="image29" src="images/image29.png"><img alt="image16" src="images/image16.png"><img alt="image6" src="images/image6.png"></p>
  <p>L’image du milieu est un test, l’image de droite est le résultat final. L’effet souhaité est présent mais on a rencontré une petite difficulté : on ne commence qu’au 20 e pixel et on ignore les 20 derniers pixels. Cela est dû au fait qu’on essayait d’accéder à des pixels qui sortent de l’image.</p>
  <h1>Luminosité</h1>
  <p><img alt="image19" src="images/image19.jpg"></p>
  <p><img alt="image1" src="images/image1.png"><img alt="image13" src="images/image13.png"></p>
  <p>Pour l’assombrissement, on prend le carré de chaque couleur.</p>
  <p>Pour l’éclaircissement, on prend la racine carrée de chaque couleur.</p>
  <h1>Disque</h1>
  <p><img alt="image25" src="images/image25.png"></p>
  <p>On applique la formule du cercle : ( x − a )^2 + ( y − b )^2 = r^2 avec :</p>
  <ul>
    <li>x et y coordonnées du pixel</li>
    <li>a et b coordonnées du centre du cercle</li>
    <li>r le rayon du cercle.</li>
  </ul>
  <h1>Cercle</h1>
  <p><img alt="image18" src="images/image18.png"></p>
  <p>On ajoute une thickness pour ne colorier qu’une fine partie du disque dessiné auparavant.</p>
  <h1>Rosace</h1>
  <p><img alt="image17" src="images/image17.png"></p>
  <p>On dessine 6 cercles supplémentaires autour du cercle central. Chaque nouveau cercle voit son centre être éloigné d’un rayon du centre du cercle initial, suivi d’un pivot de multiple de 60°. On obtient PI avec arccos(-1).</p>
  <h1>Mosaïque</h1>
  <p><img alt="image30" src="images/image30.png"><img alt="image6" src="images/image6.png"></p>
  <p>Pendant qu’on parcourt la grande image, on reboucle sur chaque cinquième pour dessiner le logo entièrement, nous laissant avec 4 boucles imbriquées.</p>
  <h1>Mosaïque Miroir</h1>
  <p><img alt="image6" src="images/image6.png"><img alt="image11" src="images/image11.png"></p>
  <p>On traite chaque cas de figure séparément, selon la ressemblance de comportement :</p>
  <p>- les petites images dont la ligne et la colonne sont impaires</p>
  <p>- les lignes impaires dont la colonne est paire</p>
  <p>- pour les lignes paires : d’abord les colonnes impaires puis les colonnes paires</p>
  <h1>Glitch</h1>
  <p><img alt="image20" src="images/image20.png"><img alt="image6" src="images/image6.png"></p>
  <p>On prend un pixel de coordonnées et dimensions aléatoires et le positionne à des coordonnées aléatoires. Les valeurs aléatoires ont des valeurs minimales et des valeurs maximales pour obtenir l’effet souhaité.</p>
  <h1>Fractale de Mandelbrot</h1>
  <p><img alt="image3" src="images/image3.png"></p>
  <p>On a séparé partie réelle et partie imaginaire parce que cela nous semblait plus clair. Pour se rapporter à l’intervalle [-2, 2], on a utilisé le produit en croix suivant : (x - a) * (d - c) / (b - a) + c avec x = valeur lue, a = valeur lue min, b = valeur lue max, c = valeur sortie min, d = valeur sortie max.</p>
  <h1>Vortex</h1>
  <p><img alt="image27" src="images/image27.png"><img alt="image6" src="images/image6.png"></p>
  <p>Le pixel subit une rotation plus conséquente autour du pixel central à mesure qu’il s’éloigne de ce dernier.</p>
  <h1>Tramage</h1>
  <p><img alt="image19" src="images/image19.jpg"><img alt="image24" src="images/image24.png"></p>
  <p>On applique la matrice 4x4 de Bayer à nos pixels pour voir si on les transforme en noir ou en blanc.</p>
  <h1>Normalisation de l'histogramme</h1>
  <p><img alt="image7" src="images/image7.png"><img alt="image10" src="images/image10.jpg"></p>
  <p>La luminosité d’un pixel est calculée en faisant la moyenne de ses 3 composantes r, g, b. Après avoir trouvé la luminosité la plus faible et la plus forte, on se rapporte à l’intervalle [0, 1] grâce à la formule citée à la fractale de Mandelbrot.</p>
  <h1>Convolutions / Netteté, Contours, etc</h1>
  <p><img alt="image6" src="images/image6.png"><img alt="image23" src="images/image23.png"></p>
  <p><img alt="image14" src="images/image14.png"><img alt="image22" src="images/image22.png"><img alt="image23" src="images/image23.png"><img alt="image2" src="images/image2.png"></p>
  <p>Le flou était relativement complexe à faire puisqu’il fallait savoir pour chaque pixel, comment itérer sur le carré de pixels l’entourant et appliquer les bons calculs. On n’a pas utilisé une matrice puisque toutes ses valeurs sont égales (1/taille^2), mais plutôt un float.</p>
  <p>Les autres convolutions étaient en revanche beaucoup plus simples puisqu’il s’agit quasiment de la même fonction que pour le flou. Il suffisait d’appliquer une matrice différente pour obtenir un résultat différent.</p>
  <h4>&nbsp;</h4>
</body>
</html>
