import axios from 'axios';

// api link
// const url = 'http://localhost:5000/api/posts/';
const url = "api/posts/"

class PostService{
    // GET
    static getPost(){ 
        return new Promise(async (resolve, reject)=>{
            try {
                const res = await axios.get(url);
                const data = res.data;
                resolve(
                    data.map(post =>({
                        ...post,
                        createdAt: new Date(post.createdAt)
                    }))
                );
            } catch (err) {  // catch error
                reject(err);
            }
        });
    }

    // CREATE
    
    static insertPost(text){
        return axios.post(url, {
            text
        });
    }

    // DELETE
    static deletePost(id){
        return axios.delete(`${url}${id}`);
    }
}

export default PostService;