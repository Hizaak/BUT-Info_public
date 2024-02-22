use("nodenot_bd1") ;

// 1. Afficher tous les articles en rupture de stock
// db.Articles.find({"QteStock": 0}) ;

// 2. Afficher tous les articles relevant de la catégorie "Epicerie"
// db.Articles.find({"Categorie": "Epicerie"}) ;

// 3. Afficher le descriptif des produits dont le taux est "Majoré"
// db.Articles.find({"Tva.LibelleTVA": "Majoré"}) ;

// 4. Dénombrer le nombre d'articles
// db.Articles.countDocuments() ;

// 5. Afficher la valeur du mois de chaque commande
// db.getCollection("Commandes").find({}, 
//     {
//         "mois": {
//             $month: "$DateCommande"
//         }
//     })

// 6. Afficher les commandes passées le 14 septembre 2007
// db.Commandes.find({
//     "DateCommande": {
//         $gte: ISODate("2007-09-14T00:00:00.000Z"),
//         $lt: ISODate("2007-09-15T00:00:00.000Z")
//     }
// }) ;

// 7. Afficher les commandes passées un lundi du mois de septembre

