import * as THREE from "three";
import { OrbitControls } from 'three/addons/controls/OrbitControls.js';
import { GLTFLoader } from 'three/addons/loaders/GLTFLoader.js';


var scene;
var camera;
var renderer;
var controls;

var floor;
var batimentUnPeuPourri;
var routeUnPeuPourie;


// j'ai juste la flemme de déclarer des variables à chaque fois (pourquoi faire sérieusement ?)
var x;
var y;
var z;


function r(min, max) {
    // Fonction qui retourne un nombre aléatoire entre min et max. Merci JavaScript :|
    return Math.floor(Math.random() * (max - min + 1) + min)
}


function generateFloatingIsland(){
    // Pour le lore : à la base le projet c'était de mettre une ville dans une galaxie, sur une île flotante avec des astéroides qui s'écrasent dedans
    // Mais puisque le modèle de bâtiment que j'ai trouvé était le World Trade Center, j'ai décidé de ne pas le faire par respect.
    const geometry = new THREE.CylinderGeometry( 100, 50, 20, 32 );
    const material = new THREE.MeshStandardMaterial( { map: new THREE.TextureLoader().load("./public/img/floor.jpg")  } );
    floor = new THREE.Mesh( geometry, material );
    floor.position.set(0,0,0);
    scene.add( floor );
}

function generateBatimentsUnPeuPourris(){
    for (let i = 0; i < 50; i++) {
        // On fait 50 bâtiments, c'et moins que New-York, mais plus que Caunette-sur-Lauquet (11082, Aude)
        x = r(10, 30);
        y = r(2, 30);
        z = r(10, 30);
        const geometry = new THREE.BoxGeometry( x, y, z);
        const material = new THREE.MeshStandardMaterial( { map: new THREE.TextureLoader().load("./public/img/building.jpg")  } );
        batimentUnPeuPourri = new THREE.Mesh( geometry, material );
        batimentUnPeuPourri.position.set(r(-100,100), 10+y/2, r(-100,100));
        // Y'a des bâtiments qui volent ? C'est pour le côté féérique... smh
        scene.add( batimentUnPeuPourri );
    }
}

function generateRouteUnPeuPourrie(){
    for (let i = 0; i < 30; i++) {
        // On fait 30 routes, c'est moins que Tokyo, mais toujours plus que Leménil-Mitry (54310, Meurthe-et-Moselle)
        x = r(50, 150);
        z = r(50, 150);
        const geometry = new THREE.BoxGeometry( x, 1, z);
        const material = new THREE.MeshStandardMaterial( { map: new THREE.TextureLoader().load("./public/img/road.jpg")  } );
        routeUnPeuPourie = new THREE.Mesh( geometry, material );
        routeUnPeuPourie.position.set(r(-100,100), 10, r(-100,100));
        // Les routes sont toutes dans le même sens et peu fonctionnelles...
        // ...
        // ...
        // ...
        // ...
        // ...
        // ...
        // ...
        // ...
        // ...
        // ...
        // ...
        // ...
        // Mais le sont toujours plus qu'à Paris...
        scene.add( routeUnPeuPourie );
    }
}

function generateWTC(){
    var loader = new GLTFLoader();
    loader.load( './public/glb/onewtc.glb', function ( wtc )
    {
        wtc.scene.position.set(0, 130, -120);

        scene.add(wtc.scene);
    } );
}

function generateRoads(){

}


// Je vous laisse le code mais ça a fait planter mon PC

// function generateRustyCars(){
//     for (let index = 0; index < 20; index++) {
//         // 20 voitures, c'est moins qu'à Madrid mais plus qu'à... C'est bon on a compris
//         x = r(10, 30);
//         y = r(2, 30);
//         z = r(10, 30);
//         var loader = new GLTFLoader();
//         loader.load( './public/glb/old_rusty_car.glb', function ( car )
//         {
//             car.scene.position.set(r(-100,100), 10, r(-100,100));
//             scene.add(car.scene);
//         } );
//     }
// }

function start(){
    // Scène
    scene = new THREE.Scene( { antialias : true });
    const loader = new THREE.TextureLoader();
    scene.background = loader.load("./public/img/scene-background.jpg")

    // Renderer
    renderer = new THREE.WebGLRenderer({ antialias: true });
    renderer.setPixelRatio(window.devicePixelRatio);
    renderer.setSize(window.innerWidth, window.innerHeight);
    renderer.shadowMap.enabled = true;
    renderer.shadowMap.type = THREE.PCFSoftShadowMap;

    document.body.appendChild(renderer.domElement);

    // PerspectiveCamera qui sert... Qui fait le travail d'une caméra en fait
    camera = new THREE.PerspectiveCamera(75,window.innerWidth / window.innerHeight,1,10000);
    camera.position.set(200, 200, 200);
    camera.lookAt(new THREE.Vector3(0, 0, 0));

    // Pour pouvoir touuuuurner
    controls = new OrbitControls( camera, renderer.domElement );


    // POUR DU DEV, à retirer !!!!!!!!
    const axesHelper = new THREE.AxesHelper( 200 );
    scene.add( axesHelper );

    // J'ai pas réussi à mettre une point light, ça aurait tout changé sinon... :'(
    // Un bel effet d'ombres fuitées... Qui s'étirent langoureusement sur la large étendue de bitume peinturluré... 
    const light = new THREE.AmbientLight( 0xDDDDDD );
    scene.add( light );


    // J'ai fait des fonctions, ça marche aussi bien que si j'avais mis un commentaire et faut regarder le code plus haut, mais c'est des fonctions
    // qui fonctionnent sinon
    generateFloatingIsland(); // Génère une ile flotante (miam !)
    generateRoads(); // Appel de fonction prankesque
    generateWTC(); // Génère le modèle du One World Trade Center. Ce projet est en fait un hommage
    generateBatimentsUnPeuPourris() // Tout est dans le nom
    generateRouteUnPeuPourrie() // idem

    renderer.render(scene, camera);

    animate();
}


function animate(){
    controls.update(); 
    controls.target.copy( floor.position ); // ça c'est pour pouvoir tourner autour du centre de l'objet floor (sol, en anglais)
    renderer.render(scene, camera);
    requestAnimationFrame(animate);
}

start();



// On vit dans une saucisse...