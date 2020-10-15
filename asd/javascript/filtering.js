

// just testing some node stuff??

let userList = {
    name: "steve",
    idList: [ "100", "101", "102", "103", "104" ]
}

let date_list = [ "100" , "101" ];
console.log("testing filtering the list to find whos sender and receiver")

// ok so use filter to set if dog is sender or receiver
userList.idList.filter(val => {
    if(val === dog_sender) sender_is_dog = true;
})


console.log(`user dog is the ${sender_is_dog? "sender" : "receiver"}`);