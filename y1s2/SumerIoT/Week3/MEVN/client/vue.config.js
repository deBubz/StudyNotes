const path = require('path');

// for deploying?

module.exports ={
    outputDir: path.resolve(__dirname, "../server/public"), // change path of built folder
    devServer:{
        proxy: {
            '/api':{
                target: 'http://localhost:5000'
            }
        }
    }
};
