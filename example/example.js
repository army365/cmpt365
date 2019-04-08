Qt.include("three.js")
Qt.include("Cloth.js")

THREE.ShaderLib['cloth'] = {

    vertexShader: [

        "varying vec2 vUV;",

        "void main() {",

            "vUV = 0.75 * uv;",

            "vec4 mvPosition = modelViewMatrix * vec4( position, 1.0 );",

            "gl_Position = projectionMatrix * mvPosition;",

        "}"

    ].join("\n"),

    fragmentShader: [

        "uniform sampler2D texture;",
        "varying vec2 vUV;",

        "vec4 pack_depth( const in float depth ) {",
            "const vec4 bit_shift = vec4( 256.0 * 256.0 * 256.0, 256.0 * 256.0, 256.0, 1.0 );",
            "const vec4 bit_mask  = vec4( 0.0, 1.0 / 256.0, 1.0 / 256.0, 1.0 / 256.0 );",
            "vec4 res = fract( depth * bit_shift );",
            "res -= res.xxyz * bit_mask;",
            "return res;",
        "}",

        "void main() {",

            "vec4 pixel = texture2D( texture, vUV );",

            "if ( pixel.a < 0.5 ) discard;",

            "gl_FragData[ 0 ] = pack_depth( gl_FragCoord.z );",

        "}"

    ].join("\n")

};

var pinsFormation = [];
var pins = [6];

pinsFormation.push( pins );

pins = [ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 ];
pinsFormation.push( pins );

pins = [ 0 ];
pinsFormation.push( pins );

pins = []; // cut the rope ;)
pinsFormation.push( pins );

pins = [ 0, cloth.w ]; // classic 2 pins
pinsFormation.push( pins );

pins = pinsFormation[ 1 ];


function togglePins() {

    pins = pinsFormation[ ~~( Math.random() * pinsFormation.length ) ];

}

var camera, scene, renderer;

var clothGeometry;
var sphere;
var object;
var pos;

var rotate = true;

function initializeGL(canvas) {
    // scene
    scene = new THREE.Scene();
    scene.fog = new THREE.Fog( 0xcce0ff, 500, 10000 );

    // camera
    camera = new THREE.PerspectiveCamera( 30, canvas.width / canvas.height, 1, 10000 );
    camera.position.y = 50;
    camera.position.z = 1500;
    scene.add( camera );

    // lights
    var light, materials;
    scene.add( new THREE.AmbientLight( 0x666666 ) );

    light = new THREE.DirectionalLight( 0xdfebff, 1.75 );
    light.position.set( 50, 200, 100 );
    light.position.multiplyScalar( 1.3 );

    light.castShadow = true;

    light.shadow.mapSize.width = 1024;
    light.shadow.mapSize.height = 1024;

    var d = 300;

    light.shadow.camera.left = -d;
    light.shadow.camera.right = d;
    light.shadow.camera.top = d;
    light.shadow.camera.bottom = -d;

    light.shadow.camera.far = 1000;

    scene.add( light );

    // cloth material

    var loader = new THREE.TextureLoader();
    var clothTexture = loader.load( 'qrc:/circuit_pattern.png' );
    clothTexture.wrapS = clothTexture.wrapT = THREE.RepeatWrapping;
    clothTexture.anisotropy = 16;

    var clothMaterial = new THREE.MeshPhongMaterial(
                { alphaTest: 0.5,
                    specular: 0x030303,
                    map: clothTexture,
                    side: THREE.DoubleSide } );

    // cloth geometry
    clothGeometry = new THREE.ParametricGeometry( clothFunction, cloth.w, cloth.h );
    clothGeometry.dynamic = true;

    var uniforms = { texture:  { type: "t", value: clothTexture } };
    var clothShader = THREE.ShaderLib[ "cloth" ];
    var vertexShader = clothShader.vertexShader;
    var fragmentShader = clothShader.fragmentShader;

    // cloth mesh

    object = new THREE.Mesh( clothGeometry, clothMaterial );
    object.position.set( 0, 0, 0 );
    object.castShadow = true;
    scene.add( object );

    object.customDepthMaterial = new THREE.ShaderMaterial(
                { uniforms: uniforms,
                    vertexShader: vertexShader,
                    fragmentShader: fragmentShader,
                    side: THREE.DoubleSide } );

    // sphere

    var ballGeo = new THREE.SphereGeometry( ballSize, 20, 20 );
    var ballMaterial = new THREE.MeshPhongMaterial( { color: 0xaaaaaa } );

    sphere = new THREE.Mesh( ballGeo, ballMaterial );
    sphere.castShadow = true;
    sphere.receiveShadow = true;
    scene.add( sphere );

    // ground

    var groundTexture = loader.load( "qrc:/grasslight-big.jpg" );
    groundTexture.wrapS = groundTexture.wrapT = THREE.RepeatWrapping;
    groundTexture.repeat.set( 25, 25 );
    groundTexture.anisotropy = 16;

    var groundMaterial = new THREE.MeshPhongMaterial( { color: 0xffffff, specular: 0x111111, map: groundTexture } );

    var mesh = new THREE.Mesh( new THREE.PlaneBufferGeometry( 20000, 20000 ), groundMaterial );
    mesh.position.y = -250;
    mesh.rotation.x = - Math.PI / 2;
    mesh.receiveShadow = true;
    scene.add( mesh );

    // poles

    var poleGeo = new THREE.BoxGeometry( 5, 375, 5 );
    var poleMat = new THREE.MeshPhongMaterial( { color: 0xffffff, specular: 0x111111, shininess: 100 } );

    var mesh = new THREE.Mesh( poleGeo, poleMat );
    mesh.position.x = -125;
    mesh.position.y = -62;
    mesh.receiveShadow = true;
    mesh.castShadow = true;
    scene.add( mesh );

    var mesh = new THREE.Mesh( poleGeo, poleMat );
    mesh.position.x = 125;
    mesh.position.y = -62;
    mesh.receiveShadow = true;
    mesh.castShadow = true;
    scene.add( mesh );

    var mesh = new THREE.Mesh( new THREE.BoxGeometry( 255, 5, 5 ), poleMat );
    mesh.position.y = -250 + 750/2;
    mesh.position.x = 0;
    mesh.receiveShadow = true;
    mesh.castShadow = true;
    scene.add( mesh );

    var gg = new THREE.BoxGeometry( 10, 10, 10 );
    var mesh = new THREE.Mesh( gg, poleMat );
    mesh.position.y = -250;
    mesh.position.x = 125;
    mesh.receiveShadow = true;
    mesh.castShadow = true;
    scene.add( mesh );

    var mesh = new THREE.Mesh( gg, poleMat );
    mesh.position.y = -250;
    mesh.position.x = -125;
    mesh.receiveShadow = true;
    mesh.castShadow = true;
    scene.add( mesh );

    //

    renderer = new THREE.Canvas3DRenderer(
                { canvas: canvas, antialias: true, devicePixelRatio: canvas.devicePixelRatio });
    renderer.setSize( canvas.width, canvas.height );
    renderer.setClearColor( scene.fog.color );

    renderer.gammaInput = true;
    renderer.gammaOutput = true;

    renderer.shadowMap.enabled = true;

}


function resizeGL(canvas) {

    camera.aspect = canvas.width / canvas.height;
    camera.updateProjectionMatrix();

    renderer.setPixelRatio(canvas.devicePixelRatio);
    renderer.setSize( canvas.width, canvas.height );

}

function toggleCamera() {

    rotate = !rotate;

}

function toggleWind() {

    wind = !wind;

}

function toggleBall() {

//    sphere.visible = !sphere.visible;

}

function paintGL(canvas) {

    var time = Date.now();

    windStrength = Math.cos( time / 7000 ) * 20 + 40;
    windForce.set( Math.sin( time / 2000 ), Math.cos( time / 3000 ), Math.sin( time / 1000 ) ).normalize().multiplyScalar( windStrength );

    simulate(time);
    render();

}

function render() {

    var timer = Date.now() * 0.0002;

    var p = cloth.particles;

    for ( var i = 0, il = p.length; i < il; i ++ ) {

        clothGeometry.vertices[ i ].copy( p[ i ].position );

    }

    clothGeometry.computeFaceNormals();
    clothGeometry.computeVertexNormals();

    clothGeometry.normalsNeedUpdate = true;
    clothGeometry.verticesNeedUpdate = true;

    sphere.position.copy( ballPosition );

    if ( rotate ) {

        camera.position.x = Math.cos( timer ) * 1500;
        camera.position.z = Math.sin( timer ) * 1500;

    }

    camera.lookAt( scene.position );

    renderer.render( scene, camera );

}
