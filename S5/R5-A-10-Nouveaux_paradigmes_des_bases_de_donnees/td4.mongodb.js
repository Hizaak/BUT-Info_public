use('nodenot_bd1');

// 1.
// db.Articles.aggregate({
//     $group: {
//         _id: "$Tva.LibelleTVA",
//         nombre: {
//             $sum: 1
//         }
//     }
// }).sort({
//     nombre: -1
// });

// 2.
// db.Articles.aggregate({
//     $match: { "Tva.TauxTVA": { $gte: 0.05 } },
// }, {
//     $group: {
//         _id: "$Tva.LibelleTVA",
//         nombre: {
//             $sum: 1
//         }
//     }
// }).sort({
//     nombre: -1
// });

// 3.
// db.getCollection("Articles").aggregate([
//     {
//         $match: {
//             Descriptif: { $regex: RegExp("paquet") },
//         },
//     },
//     {
//     $group: {
//         _id: null,
//         moyenne: { $avg: "$PrixHT" },
//         },
//     },
// ],
//     { maxTimeMS: 60000, allowDiskUse: true }
// );

// 4.
// db.Articles.aggregate({
//     $project: {
//         _id: 0,
//         "Tva.LibelleTVA": 1,
//         "Tva.TauxTVA": 1,
//         "PrixHT": 1,
//         "PrixTTC": { $round: [ { $multiply: [ "$PrixHT", { $add: [ 1, "$Tva.TauxTVA" ] } ] }, 2 ] }
//     }
// })

// 5.
// db.Articles.aggregate([
//     {
//         $match: {
//             "Categorie": "Epicerie",
//             PrixHT: { $gte: 2.0, $lte: 5.0 }
//         }
//     },
//     {
//         $group: {
//             _id: null,
//             prixMax: { $max: "$PrixHT" },
//             prixMin: { $min: "$PrixHT" },
//             prixMoyen: { $avg: "$PrixHT" }
//         }
//     }
// ])

// 6.
// db.Commandes.aggregate([
//     {
//         $unwind: "$LignesDeCommande"
//     },
//     {
//         $group: {
//             _id: "$Numero",
//             nombre: { $sum: 1 }
//         }
//     }
// ])

// 7.
// db.getCollection('Commandes').aggregate(
//     [
//       { $match: { Numero: 1101 } },
//       { $unwind: { path: '$LignesDeCommande' } },
//       {
//         $lookup: {
//           from: 'Articles',
//           localField: 'LignesDeCommande.Article',
//           foreignField: '_id',
//           as: 'result'
//         }
//       },
//       { $unwind: { path: '$result' } },
//       {
//         $set: {
//           Chiffrage: {
//             $multiply: [
//               '$LignesDeCommande.Quantite',
//               '$result.PrixHT',
//               { $add: [1, '$result.Tva.TauxTVA'] }
//             ]
//           }
//         }
//       },
//       {
//         $project: {
//           _id: 1,
//           Numero: 1,
//           NomClient: 1,
//           Chiffrage: 1
//         }
//       },
//       { $group: {
//         _id: "$Numero",
//         "Chiffrage": {
//           $sum: "$Chiffrage"
//         }
//       }}
//     ],
//     { maxTimeMS: 60000, allowDiskUse: true }
//   );

// 8.
db.getCollection('Commandes').aggregate(
    [
        { }
    ]);