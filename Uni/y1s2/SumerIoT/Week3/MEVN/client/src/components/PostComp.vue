<template>
  <div class="container">
    <h1>Lastest Posts</h1>
    <!-- CREATE POST ERE -->
    
    <div class="create-post">
      <label for="create-post">Something</label>
      <input type="text" id="create-post" v-model="text" placeholder="create a post"> <!-- v-model to attach to data(){text}-->
      <button v-on:click="createPost">post</button>
    </div>

    <hr>
    <!-- List post -->
    <p class="error" v-if="error">{{error}}</p><!--on if error is true-->
    <div class="post-container">
      <div class="post"
        v-for="(post, index) in posts"
        v-bind:item="post"
        v-bind:index="index"
        v-bind:key="post._id"
        v-on:dblclick ="deletePost(post._id)"
      >
      {{ `${post.createdAt.getDate()}/${post.createdAt.getMonth()}/${post.createdAt.getFullYear()}`}}
      <p class="text">{{post.text}}</p>
      
      </div>
    </div>
    </div>
</template>

<script>
import PostService from '../PostService'

export default {
  name: 'PostComp',
  data(){
    return{
      posts: [],
      error: "",
      text: ''
    }
  },
  async created(){
    try {
      this.posts = await PostService.getPost();
    } catch (err) {
      this.error = err.message;
      
    }
  },
  methods: {
    async createPost(){
      try {
        await PostService.insertPost(this.text);

        this.posts = await PostService.getPost();
        // this.post = await PostService.getPost();
      } catch (err) {
        this.error= err.message;
      }

    },
    async deletePost(id){
      await PostService.deletePost(id);
      this.posts = await PostService.getPost();
    }
  },
}
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped>
div.container{
  max-width: 800px;
  max-width: 0 auto;
}

p.error{
  border:  1px solid lightcoral;
  background-color: pink;
  padding: 10px;
  margin-bottom: 15px;
}

div.post{
  position: relative;
  border: 1px solid greenyellow;
  background-color: lightgreen;
  padding: 10px 10px 30px 10px;
  margin-bottom: 15px;
}

div.createdAt{
  position: absolute;
  top: 0;
  left: 0;
  padding: 5px 15px 5px 15px;
  background-color: darkgreen;
  color:wheat;
  font-size: 13px;
}

p.text{
  font-size: 22px;
  font-weight: 700;
  margin-bottom: 0;
}
/* ------------ */
h3 {
  margin: 40px 0 0;
}
ul {
  list-style-type: none;
  padding: 0;
}
li {
  display: inline-block;
  margin: 0 10px;
}
a {
  color: #42b983;
}
</style>
