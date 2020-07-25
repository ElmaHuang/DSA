# Article Categories

{% embed url="https://wiki.scn.sap.com/wiki/display/PLM/Getting+Started+in+the+Article+Master" %}

Article Categories:

Single material \(industry\) \(MARA-ATTYP initial\): ‚Standard'-Materials of non-Retail systems, created for instance by MM01.

Single article \(MARA-ATTYP = 00\): Individually created articles similar to standard-materials.

Generic article \(MARA-ATTYP = 01\): Generic articles do not exist physically and are not sold, but do only exist as a data reference for variants.

Variants \(MARA-ATTYP = 02\): Article of the kind of the generic article, but with special characteristic values. To the generic article 'shirt' for example, one can have the variant: shirt, white, size XL'.

Sales Set \(MARA-ATTYP = 10\): A set is a combination of several articles which are bought individually and sold together, for example a bottle of wine together with two wineglasses. The components are been deposit in the basic data view at the button 'components'. Technically, a set is handled like a BOM and stored in BOM database tables. You should not maintain a set by BOM transactions, however.

Prepack \(MARA-ATTYP = 11\): A lot is a collection of different articles that are bought together and sold individually, thus more or less the opposite of a set. Shoes would be a good example: They are bought als a collection of shoes with different sizes \(for example one of size 39 three of size 40 ... two of size 45 etc.\). Prepack allocation plans are maintained in transaction WSTN11. From the technical point of view, prepacks are also plant-independant BOMs.

Display \(MARA-ATTYP = 12\): A Display is a collection of articles which are, similar to prepack, bought together and sold individually, including special packaging. An example would be at Christmas time the paper figure of Santa Claus, holding different types of chocolate: the manufacturer delivers the whole figure, the store sells the individual chocolates. Again, this is technically a BOM.

Material group article \(MARA-ATTYP = 20\) 

Hierarchy article \(MARA-ATTYP = 21\) 

Group material \(MARA-ATTYP = 22\) 

Material group reference article \(MARA-ATTYP = 30\)

