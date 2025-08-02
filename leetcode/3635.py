class Solution:
    def earliestFinishTime(
        self,
        landStartTime: List[int],
        landDuration: List[int],
        waterStartTime: List[int],
        waterDuration: List[int],
    ) -> int:
        landLength, waterLength = len(landStartTime), len(waterStartTime)
        landEndStartDurationTime = [
            (landStartTime[i] + landDuration[i], landStartTime[i], landDuration[i])
            for i in range(landLength)
        ]
        minLandEndStartDurationTime = min(landEndStartDurationTime)
        waterEndStartDurationTime = [
            (waterStartTime[j] + waterDuration[j], waterStartTime[j], waterDuration[j])
            for j in range(waterLength)
        ]
        minWaterEndStartDurationTime = min(waterEndStartDurationTime)
        return min(
            *[
                (
                    minLandEndStartDurationTime[0] + waterEndStartDurationTime[i][2]
                    if minLandEndStartDurationTime[0] > waterEndStartDurationTime[i][1]
                    else waterEndStartDurationTime[i][0]
                )
                for i in range(waterLength)
            ],
            *[
                (
                    minWaterEndStartDurationTime[0] + landEndStartDurationTime[i][2]
                    if minWaterEndStartDurationTime[0] > landEndStartDurationTime[i][1]
                    else landEndStartDurationTime[i][0]
                )
                for i in range(landLength)
            ]
        )
