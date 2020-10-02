- [Background](#background)
- [Location & Localisation](#location--localisation)
  - [`Categorisation of Positions`](#categorisation-of-positions)
  - [`Classification of localisation methods`](#classification-of-localisation-methods)
  - [Range based techniques](#range-based-techniques)
- [Clustering](#clustering)
  - [node v data clustering](#node-v-data-clustering)
- [Data aggregation](#data-aggregation)
  - [aggregation types](#aggregation-types)
  - [aggretion by voting methods](#aggretion-by-voting-methods)
  - [data aggregation models](#data-aggregation-models)
    - [centralised & decentralised](#centralised--decentralised)
    - [hierachical aggregarion Model](#hierachical-aggregarion-model)
    - [summary: aggregation](#summary-aggregation)
- [Clustering](#clustering-1)
  - [Clustering taxonomy](#clustering-taxonomy)
- [Routing](#routing)
  - [Taxonomy of Routing protocols](#taxonomy-of-routing-protocols)
- [Taxonomy of Network Structure in Routing](#taxonomy-of-network-structure-in-routing)
  - [Flat based Routing protocols](#flat-based-routing-protocols)
  - [Heirachical Routing](#heirachical-routing)
  - [Location Based Routing](#location-based-routing)
  - [Routing protocols based on Protocol Operation](#routing-protocols-based-on-protocol-operation)
  - [Hierachical v Flat](#hierachical-v-flat)
  - [Routing Protocal Classification & Comparison](#routing-protocal-classification--comparison)
- [Summary](#summary)

Oh shit there is alot

> Localisation, Aggretion, Clustering and routing

- Background
- Location & localisation: classification & sensor localisation methods
- Aggretion & methods
- Clustering
- Routing & protocols

---

## Background

**RECAP** factors influencing IoT Design

IoT needs to address *localisation*, *clustering*, *aggregation* & *routing*.
Applied algos can contribute or be very detrimental to scalability, robustness, efficiency & effective management of resources.

- **localisation**
- **clusterisation**
- **data aggretion**
- **routing**
- **mobility of nodes**
- **autonomics**
- **fault tollerance & redundancy**
- **scalability**
- **cost**

**Case Study** Localisation, Clustering, Aggregation & Routing in Precision Agriculture

Knowledge of sensor location with IoT help with:

- location of sensed even in the world
- location-aware services
- location of primary sensors info (logistics, supply chain, sec and surveillance)
- clustering/ self-org (autonomics) of sensors
- aggregation  of data helps to reduce redundancies and make telemetry more efficient
- obj tracking
- routing data & protocols are based on geographic information (routing)
- coverege area management

--- 

## Location & Localisation

- **Location (position)**
- **Localisation (positioning)**

### `Categorisation of Positions`

- **Global**
  - pos within general global reference frame
  - GPS longitudes, latitudes
  - universal transverse mercator UTM (zones & latitude bands)
- **Relative**
  - based on arbitrary coordinate systems & reference frames
  - distances btween sensors
- **Symbolic** positional info 
- **Accuracy v Presicision**

> Overview of localisation
>
> N = m + n total num of nodes
>
> m ... num of beacons
>
> n ... num of unknowns

### `Classification of localisation methods`

- **Localisation** studied in vision, robotics, signal processing
- Solutions can be classified as:
  - **range based** & **range free** technuques
  - **one hop** or **multi hop** techniques
  - aboslute, relative or local coords
  - centralized, distributed or localised algos
- Possible Methods
  - Lateration (common) - use recieved signal strength RSS to estimate distance (comine with triangulation)
  - Angulation
  - proximity

### Range based techniques

- Time difference of Arrival
- Angle of Arrival
- Recieved Signal Strength (RSS)
- Triangulation
- Trilateration
- Iterative/Collaborative Multilateration
- GPS-based localisation
- Ad Hoc Positioning System
- Event-driven localisation

## Clustering

**Node Clustering**
 
- grouping IoT nodes into clusters representing collection of many nodes
- the nides comunicate with each other to perform operations at high rates.
- Each node is a single device

> how are they organised

### node v data clustering

- **node** allows coordinating local info efficiently => facilitate robustness, scalability, efficiency & effective management of resources
  - clusters often formed in the bootstrap phase
  - the cluster member nodes elect a *cluster head* performing aggregation, routing and arbitration tasks for the cluster.
  - dynamic clustering is a result of reconfiguration in later stages
- **data clustering** different from sensor/nodes clustering ??? what the fuck

---

## Data aggregation

- this is an essential paradigm for routing in IoT
- its best to combine data from different sources - eliminating redundancy, minimising no. of transmissio -> saving energy
- **data aggregation** shift the focus from 
  - address-centric methods for networking ( finding short routes btween pairs of addressable end-nodes )
  - to a more-data centric approach ( finding routes from multi sources -> single destination that allows in-network consolidation of redundant data )

**concepts**

- **process**
  - collects result from many nodes
  - result aggregated with nodes own based on a decision criterion
  - aggregated data are then sent to another node/base station

> what the fuck

> What to ask
> - what instace of a sensed event should a node aggregate and report
> - what data aggregation architecture should be used
> - how a node aggregate/fuse multiple reports into a single one

### aggregation types

- **cyclic (periodical)**
- **base station inquiry response**
- **event triggered**

### aggretion by voting methods

- the most old and widely used aggregation decision m ethod
- aggregation nodes arrives at a sonsensus by applying a boting scheme
  - majority voting
  - complete agreement
  - weighted voting
- its popularity is from its simplicity and accuracy
- other aggregation decision algo include
  - probability based bayesian model
  - stack generalisation

### data aggregation models

- centralised
- decentralised
- hierachical
  - tree/ cluster/ grid based
- flat structure
- hybrid
- federated

#### centralised & decentralised

**centralised**

- data aggregation occurs centrally ont he basis of global obs from all nodes
- central processor nodes
- advantages
  - ease on implementation & contrl
  - limited latencies

**decentralised**

- data aggregation occurs locally at each node on the basis of local obs and the information obtained from neighbour nodes.
- no central processor node
- advantages:
  - scalable and tolerant ti addition/loss of sensing nodes
  - or dynamic changes in the network

> - should data aggregation be centralised or decentralise
> - what level of autonomy should we have for aggregation

#### hierachical aggregarion Model

- nodes are partitioned into hierachical levels
- nodes at lv0, basestation at highest
- reports move from lower to higer, workload is balanced among nodes

more things on the model

- **cluster based data aggregation**
- **aims of cluster based data aggregation**

**problem** node synchronization

> THIS IS BECAUSE LATENCY

#### summary: aggregation 

- There is still ALOT more to data aggregation
- An ideal model of data aggregation will be the one that are:
  - energy efficiency
  - synchronisation among sensors
  - resistant against attacks
- Data aggregation is a trade-off
  - it saves on energy processing resources
  - BUT introduce transmission delays

---

## Clustering

Network performance in important in IoT
- retransmission & dropped packets waste energy
- since the network is usually dence and several nodes are redundant
  - network lifetime is measured by the time that the system is available for providing services
- **pros**
  - increase network scalability
  - support data aggregation
  - reduce comminication overhead for both single and multihop
  - transmit aggregated data into the data sink

> sl 50

- **clustering process**
  1. cluster network divided into subnets
  2. each node group contains a single leader **cluster head**
  3. normal nodes transmit data to the **cluster head** for aggregation
  4. aggregated data is then transfered to base station

### Clustering taxonomy

- cluster based grouping of similar objects in our context
  - distance/proximity
  - logical organisation
- Topolgy control approach
  - distance/proximity
  - load balancing, network scalability
- Clustering types
  - static: local topology control
  - dynamic: changing network parameters
  - single hop & multihop
  - HOmogeneous & hetero geneous

--- 

## Routing

**Definition**:
IoT routing denote the arranging(scheduling) of sensor/control data 
for delivery according to scheduled sequence.

IoT are large in scale;
Routing means deciding the "best" **routing path** to transfer data packets.
The more nodes there are in the **routing path**, the more **complex** the rouing is

**Routing Issues**
- global ID addresing (using both IPv4 & IPv6)
- IP-based protocols ?man? not always apply
- stationary v mobile nodes
- energy, storagem processing contraints
- high redundancy in different sensor data, actuation controll

### Taxonomy of Routing protocols

Categorisation of IoT routing algos

- path establishment
- network strucure
- protocol operation
- initiator of communication

> sl55

## Taxonomy of Network Structure in Routing

Routing protocol are of these categories

- FlatBased
- Hierarchical Based
  - High energy node `transmit`
  - Low evergy node `sense`
  - 2 layer routing increase lifetime
- Location Based
  - sensor nodes addressed based on location
  - Location from GPS or coordination among nodes

### Flat based Routing protocols

1. Sensor protocol for Information Negotiation (SPIN)
2. Directed Diffusion
3. RumorRouting
4. Minimum cost forwarding Algo (MCFA)

### Heirachical Routing

1. Low Energy Adaptive Clustering Hierachy (LEACH)
2. Self Organizing Protocol (SOP)
3. Virtual Grid Architecture
4. Hierachical power aware routing

> sl61 LEACH example

### Location Based Routing

1. Gerographical Adaptive Fidelity (GAF)
2. SPAN 

### Routing protocols based on Protocol Operation

1. Multipath Routing
2. Query based Routing
3. Negotiation based Routing
4. QoS based routing

> Examples sl64-67 

### Hierachical v Flat

| Heirarchical routing | Flat Routing |
|:---|:---|
|reservation based scheduling | connection based scheduling |
|collision avoided | collision overhead present |
| reduced duty cycle due to periodic sleeping | variable duty cycle by controlling sleep time of nodes |
| data aggregation by `clusterhead` | node on multihop path aggregate incomming data from neighbours |
| Simple, non-optimal routing | can be optimal and complex |
| link `requires` global and local sync | link forms `without` sync |
| overhead of clusters formation in network | routes only formed in regions that have data ready for transmission |
| low latency as multiple hops network formed by clusterheads `always available` | latency in `waking up` intermediate nodes and setting the multipath | 
| `uniform` energy dissapation | energy dissapation `depends` on traffic patern |
| energy dissapation `cannot be controlled` | energy dissapation `addapts` to traffic pattern |
| fair channel allocation | fairness not guaranteed |

### Routing Protocal Classification & Comparison

> sl69

---

## Summary

- viewd the basic frameworks for **localisation**, **aggregation**, **clustering** and **routing**
  - algos differ in *node selection*, *aggregation methods*, *cluster formation* and *routing*
  - some address intra/inter cluster comminication
- **clustering** improves utilisation of all available information and not only subset of parameters. It yield **better network performance** by:
  - reduce power consumption -> prolongs network lifetime
  - formation cluster from a set of nodes
  - cluster the whole network with the selected CH and rotates CHs for energy distribution