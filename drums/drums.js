Qt.include("three.js")

var scene, camera, renderer, light;
var kick, snare, crash, hihat;

function initializeGL(canvas) {
    // Scene initialization
    scene = new THREE.Scene();
//    scene.fog = new THREE.Fog(0x222222, 20, 600);

    // Camera initialization
    camera = new THREE.PerspectiveCamera( 75, canvas.innerWidth / canvas.innerHeight, 10, 600 );
    camera.position.z = 90;
    camera.position.y = 60;

    // Light initialization
    var ambientLight = new THREE.AmbientLight(0x222222);
    scene.add(ambientLight);

    var hemiLight = new THREE.HemisphereLight( 0xFFF7EB, 0xEBF7FD, 0.3 );
    hemiLight.position.set( 0, 100, 0 );
    scene.add( hemiLight );

    light = new THREE.SpotLight( 0xffffff );
    light.position.y = 120;
    light.position.x = 0;
    light.position.z = 60; //110;
    light.angle = Math.PI / 6;

    light.castShadow = true;

    light.shadow.mapSize.width = 1024;
    light.shadow.mapSize.height = 1024;

    light.shadow.camera.near = 1;
    light.shadow.camera.far = 800;
    light.shadow.camera.fov = 100;

    scene.add( light );
    scene.position.x = -12;

    // Ground initialization
    scene.add(ground());

    // Drums initialization
    var drumMaterial = new THREE.MeshPhongMaterial({
        color: 0xd22442,
        specular: 0x4a4646,
        shininess: 74,
        emissive: 0x48180a,
        emissiveIntensity: 0.5,
        transparent: true,
        opacity: 0.8,
    });

    var drumFrontMaterial = new THREE.MeshPhongMaterial({
        color: 0xFFFFFF,
        //specular: 0x009900,
        shininess: 550,
        emissive: 0xFFFFFF,
        emissiveIntensity: 0.5,
        transparent: true,
        opacity: 0.95,
    });

    var geometry1 = new THREE.CylinderGeometry( 20, 20, 30, 50 );
    kick = new THREE.Mesh(geometry1, drumMaterial);

    var frontGeometry = new THREE.CylinderGeometry( 18, 18, 1, 50 );
    var front = new THREE.Mesh(frontGeometry, drumFrontMaterial);
    //front.position.z = 18;
    front.position.y = 15;
    front.castShadow = true;
    front.receiveShadow = true;
    kick.add(front);
    kick.position.x = 20;
    kick.position.y = 20;
    kick.rotation.x = Math.PI / 2;
    kick.castShadow = true;
    kick.receiveShadow = true;
    scene.add(kick);

    var geometry2 = new THREE.CylinderGeometry( 10, 10, 9, 50 );
    snare = new THREE.Mesh(geometry2, drumMaterial);

    var frontGeometry2 = new THREE.CylinderGeometry( 9, 9, 1, 50 );
    var front2 = new THREE.Mesh(frontGeometry2, drumFrontMaterial);
    front2.position.y = 4.5;
    front2.castShadow = true;
    front2.receiveShadow = true;
    snare.add(front2);
    snare.position.x = -20;
    snare.position.z = 20;
    snare.position.y = 25;
    snare.castShadow = true;
    snare.receiveShadow = true;
    scene.add(snare);

    // Pedal initialization
    var pedalGeometry = new THREE.BoxGeometry(8, 5, 20);
    var pedalMaterial = new THREE.MeshPhongMaterial({
        color: 0x6C7A89,
        //specular: 0x009900,
        shininess: 100,
        emissive: 0x6C7A89,
        emissiveIntensity: 0.6,
    });

    var pedal = new THREE.Mesh(pedalGeometry, pedalMaterial);
    pedal.castShadow = true;
    pedal.receiveShadow = true;
    pedal.position.x = -8;
    pedal.position.z = 5;
    pedal.rotation.y = Math.PI / 8;
    scene.add(pedal);


    // Cymbal initialization
    var cymbalMaterial = new THREE.MeshPhongMaterial({
        color: 0xcaa347,
        specular: 0x726216,
        shininess: 50,
        emissive: 0x593f0d,
        emissiveIntensity: 0.5,
        transparent: false
    });

    var geometry3 = new THREE.CylinderGeometry( 13, 13, 1, 50 );
    crash = new THREE.Mesh(geometry3, cymbalMaterial);

    crash.position.x = 43;
    crash.position.z = 15;
    crash.position.y = 40;
    crash.rotation.x = Math.PI / 8;
    crash.castShadow = true;
    crash.receiveShadow = true;
    scene.add(crash);

    var geometry4 = new THREE.CylinderGeometry( 10, 10, 1, 30 );
    hihat = new THREE.Mesh(geometry4, cymbalMaterial);

    var bottomhat = new THREE.Mesh(geometry4, cymbalMaterial);
    bottomhat.position.y = 2;
    bottomhat.castShadow = true;
    bottomhat.receiveShadow = true;
    hihat.add(bottomhat);
    hihat.position.x = -4;
    hihat.position.z = 10;
    hihat.position.y = 40;
//    hihat.rotation.x = Math.PI/6;
    hihat.castShadow = true;
    hihat.receiveShadow = true;
    scene.add(hihat);

    // Render initialization
    renderer = new THREE.Canvas3DRenderer(
                { canvas: canvas, antialias: true, devicePixelRatio: canvas.devicePixelRatio });
    renderer.setClearColor( 0x000000 );
    renderer.setSize( canvas.width, canvas.height );
    renderer.toneMapping = THREE.LinearToneMapping;
    renderer.toneMappingExposure = Math.pow( 0.91, 5.0 );
    renderer.shadowMap.enabled = true;
    renderer.shadowMap.type = THREE.PCFSoftShadowMap;
}

function paintGL(canvas) {
    render();
}

function resizeGL(canvas) {
    camera.aspect = canvas.width / canvas.height;
    camera.updateProjectionMatrix();

    renderer.setPixelRatio(canvas.devicePixelRatio);
    renderer.setSize( canvas.width, canvas.height );
}

function render() {
    camera.lookAt(new THREE.Vector3(0, 0, 0));
    renderer.render( scene, camera );
    snare.rotation.x = 0;
    hihat.rotation.x = 0;
    kick.rotation.x = Math.PI / 2;
    crash.rotation.x = Math.PI / 8;
}

function ground() {
    var loader = new THREE.TextureLoader();
    var groundTexture = loader.load( 'qrc:/Wood_011_basecolor.jpg' );
    groundTexture.wrapS = groundTexture.wrapT = THREE.RepeatWrapping;
    groundTexture.anisotropy = 16;

    var geometry = new THREE.PlaneGeometry( 600, 600, 1, 1 );

    var material = new THREE.MeshPhongMaterial({
        alphaTest: 0.5,
        specular: 0x030303,
        map: groundTexture,
        side: THREE.DoubleSide
    });

    var plane = new THREE.Mesh( geometry, material );
    plane.rotation.x = Math.PI / -2;
    plane.receiveShadow = true;
    return plane;
}

function getKey(key) {
    switch(key){
    case "KeyG":
        snare.rotation.x = Math.PI / 16;
        break;
    case "KeyH":
        hihat.rotation.x = Math.PI / 16;
        break;
    case "KeyB":
        kick.rotation.x = Math.PI / 3;
        break;
    case "KeyV":
        crash.rotation.x = Math.PI / 16;
        break;
    }
}
