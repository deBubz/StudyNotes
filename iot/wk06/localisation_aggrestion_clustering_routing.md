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


