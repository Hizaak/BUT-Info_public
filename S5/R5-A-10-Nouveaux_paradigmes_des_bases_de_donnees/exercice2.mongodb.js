use('nodenot_bd2');
// 1. Quels sont les sportifs (identifiant, nom et prénom) ayant entre 35 et 45 ans ? Proposez deux solutions.
// db.sportifs.find(
//     {
//         $and: [
//             { Age: { $gte: 35 } },
//             { Age: { $lte: 45 } }
//         ]
//     },
//     { Nom: 1, Prenom: 1 }
// )

// OU

// db.sportifs.find(
//     {
//         Age: {
//             $gte: 35,
//             $lte: 45
//         }
//     },
//     { Nom: 1, Prenom: 1 }
// )

// 2. Combien y-a-t-il de sportifs qui jouent au Badmington ou au Foot ?
// db.sportifs.find(
//     {
//         $or: [
//             { "Sports.Jouer": "Badmington" },
//             { "Sports.Jouer": "Foot" }
//         ]
//     }).count()

// 3. Combien y-a-t-il de sportifs qui jouent à la fois au Tennis, au Foot et au Volley sans disposer de sportif pour les conseiller ?
// db.sportifs.find(
//     {
//         "Sports.Jouer" : {
//             $all : [
//                 "Tennis",
//                 "Football",
//                 "Volley ball"
//             ]
//         },
//         IdSportifConseiller: { $exists : false }
//     }
// ).count()

// 4. Quels sont les sportifs qui pratiquent 5 sports ?
// db.sportifs.find(
//     {
//         "Sports.Jouer": {
//             $size : 5 
//         }
//     }
// )

// 5.  Quels sportifs (nom et prénom) entrainent mais ne sont pas des arbitres ? 
// db.sportifs.find(
//     {
//         "Sports.Arbitrer" : { $exists : false },
//         "Sports.Entrainer" : { $exists : true },
//     }
// )

// 6.  Quels sont les gymnases dont le nom a été donné en hommage à un écrivain et pour lesquels la clé OrigineNom commence par "P" ? 
// db.gymnases.find(
//     {
//         OrigineNom: {
//             $regex: "^P.*écrivain",
//         }
//     }
// )

// 7. Dans combien de gymnases entraîne le sportif dont l’IdSportif vaut 149 ?
// db.gymnases.find(
//     {
//         "Seances.IdSportifEntraineur": 149
//     }
// ).count()

// 8. Dans quels gymnases de "STAINS" peut-on s’entrainer à un sport de balle le dimanche ?
// db.gymnases.find({
//     "Ville": "STAINS",
//     "Seances": {
//         $elemMatch: {
//         "Jour": { $regex: ".imanche" },
//         "Libelle": { $regex: /ball$/i }
//         }
//     }
// }).count()

// 9. Quels sont les joueurs de moins de 30 ans qui ont renseigné le Basket Ball comme premier sport pratiqué ?
// db.sportifs.aggregate([    {
//         $match: {
//         Age: { $lt: 30 }, // Filtrer les joueurs de moins de 30 ans
//         "Sports.Jouer.0": { $regex: /basket/i } // Vérifier que le premier sport pratiqué correspond au basket (insensible à la casse)
//         }
//     }
// ])

// 10. Quelles sont les informations connues sur la dernière séance enregistrée pour les seuls gymnases de STAINS
// db.gymnases.find({
//     "Ville" : "STAINS",
// }, {
//     "_id": 0,
//     "NomGymnase": 1,
//     "Ville": 1,
//     "Seances": {
//         $slice: -1
//     }
// })


// db.getCollection('gymnases').aggregate(
//     [
//       { $unwind: { path: '$Seances' } },
//       {
//         $group: {
//           _id: '$_id',
//           listeSports: {
//             $addToSet: '$Seances.Libelle'
//           },
//           IdGymnase: { $first: '$IdGymnase' }
//         }
//       }
//     ],
//     { maxTimeMS: 60000, allowDiskUse: true }
//   );
// db.gymnases.find({})