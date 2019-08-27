function route(handle, pName){
    console.log("Routing a rq for "+ pName);
    if(typeof handle[pName]=== 'function'){
        handle[pName]();
    }
    else{
        console.log("no req handler for "+pName);
    }
    
}

exports.route = route;