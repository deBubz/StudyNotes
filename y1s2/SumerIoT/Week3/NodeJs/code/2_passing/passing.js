// consider this

function say(thing){
    console.log(thing);
}

function exe(action, arg){
    action(arg);
}

exe(say,"hey");

// where the exe() uses say() as an arguement
// now it is not needed to declare seperate functions
// you can pass the whole func as a param

function execute(action, arg){
    action(arg);
}

execute(function(work){
    console.log(word);
}, "word");

// comparing this to the first block of code
// the func say() is passed directly as a param


